import requests

def count_words(subreddit, word_list, keyword_count={}, next_page=None, reap_keyword={}):
    headers = {"User-Agent": "Goomba"}
    api_url = f'https://reddit.com/r/{subreddit}/hot.json'
    params = {'after': next_page} if next_page else {}

    response = requests.get(api_url, headers=headers, params=params)
    if response.status_code != 200:
        return

    data = response.json()['data']
    next_page = data.get('after')
    posts = data.get('children', [])

    if not keyword_count:
        keyword_count = {word: 0 for word in word_list}
        reap_keyword = {word: word_list.count(word) for word in word_list}

    for post in posts:
        title_words = post['data'].get('title', '').split()
        for word in title_words:
            for key in keyword_count:
                if word.lower() == key.lower():
                    keyword_count[key] += 1

    if next_page:
        count_words(subreddit, word_list, keyword_count, next_page, reap_keyword)
    else:
        for keyword, count in reap_keyword.items():
            keyword_count[keyword] *= count

        sorted_results = sorted(keyword_count.items(), key=lambda x: (-x[1], x[0]))
        for keyword, count in sorted_results:
            if count > 0:
                print(f'{keyword}: {count}')
