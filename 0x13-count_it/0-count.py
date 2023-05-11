#!/usr/bin/python3
"""
main module
"""
import requests


def count_words(subreddit, word_list, after=None, count_dict=None):
    """
    Function to count reddit subreddits
    """
    if count_dict is None:
        count_dict = {}

    if after is None:
        url = "https://www.reddit.com/r/{}/hot.json".format(subreddit)
    else:
        url = "https://www.reddit.com/r/{}/hot.json?after={}".format(
            subreddit, after)

    headers = {
        "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64)"}
    response = requests.get(url, headers=headers, allow_redirects=False)

    if response.status_code == 200:
        data = response.json()
        posts = data['data']['children']
        for post in posts:
            title = post['data']['title']
            words = title.lower().split()
            for word in word_list:
                if word.lower() in words:
                    count_dict[word] = count_dict.get(
                        word, 0) + words.count(word.lower())

        after = data['data']['after']
        if after is not None:
            return count_words(subreddit, word_list, after, count_dict)
    else:
        pass

    sorted_counts = sorted(count_dict.items(), key=lambda x: (-x[1], x[0]))
    for word, count in sorted_counts:
        print("{}: {}".format(word.lower(), count))
