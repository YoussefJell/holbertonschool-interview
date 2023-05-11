#!/usr/bin/python3
"""
main module
"""
import requests


def count_words(subreddit, word_list, keyowrds={}, next_pg=None, rep_kw={}):
    """all hot posts by keyword"""
    headers = {"User-Agent": "Goomber"}

    if next_pg:
        subr = requests.get('https://reddit.com/r/' + subreddit +
                            '/hot.json?after=' + next_pg, headers=headers)
    else:
        subr = requests.get('https://reddit.com/r/' + subreddit +
                            '/hot.json', headers=headers)

    if subr.status_code == 404:
        return

    if keyowrds == {}:
        for word in word_list:
            keyowrds[word] = 0
            rep_kw[word] = word_list.count(word)

    subr_dict = subr.json()
    subr_data = subr_dict['data']
    next_pg = subr_data['after']
    subr_posts = subr_data['children']

    for post in subr_posts:
        post_data = post['data']
        post_title = post_data['title']
        title_words = post_title.split()
        for w in title_words:
            for key in keyowrds:
                if w.lower() == key.lower():
                    keyowrds[key] += 1

    if next_pg:
        count_words(subreddit, word_list, keyowrds, next_pg, rep_kw)

    else:
        for key, val in rep_kw.items():
            if val > 1:
                keyowrds[key] *= val

        sorted_abc = sorted(keyowrds.items(), key=lambda x: x[0])
        sorted_res = sorted(sorted_abc, key=lambda x: (-x[1], x[0]))
        for res in sorted_res:
            if res[1] > 0:
                print('{}: {}'.format(res[0], res[1]))
