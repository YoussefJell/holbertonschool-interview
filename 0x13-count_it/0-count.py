import requests
""" 0-count module """


def count_words(subreddit, word_list, kw_count={}, next_page=None, repkw={}):
    """ function count_words """

    headers = {"User-Agent": "Goomba"}
    api_url = f'https://reddit.com/r/{subreddit}/hot.json'
    params = {'after': next_page} if next_page else {}

    response = requests.get(api_url, headers=headers, params=params)
    if response.status_code != 200:
        return

    data = response.json()['data']
    next_page = data.get('after')
    posts = data.get('children', [])

    if not kw_count:
        kw_count = {word: 0 for word in word_list}
        repkw = {word: word_list.count(word) for word in word_list}

    for post in posts:
        title_words = post['data'].get('title', '').split()
        for word in title_words:
            for key in kw_count:
                if word.lower() == key.lower():
                    kw_count[key] += 1

    if next_page:
        count_words(subreddit, word_list, kw_count, next_page, repkw)
    else:
        for keyword, count in repkw.items():
            kw_count[keyword] *= count

        sorted_results = sorted(kw_count.items(), key=lambda x: (-x[1], x[0]))
        for keyword, count in sorted_results:
            if count > 0:
                print('{}: {}'.format(keyword, count))
