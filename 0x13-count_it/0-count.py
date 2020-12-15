#!/usr/bin/python3
"""Count it! hot tittles"""
import requests


def count_words(subreddit, word_list, cont={}, next_page=None, new_dict={}):
    """queries recursively hot titles"""

    headers = {"User-Agent": "xtian"}
    if next_page:
        queri1 = 'https://reddit.com/r/' + subreddit
        queri = queri1 + '/hot.json?after=' + next_page
        r = requests.get(queri, headers=headers)
    else:
        url = 'https://reddit.com/r/{}/hot.json'.format(subreddit)
        r = requests.get(url, headers=headers)

    if r.status_code == 404:
        return

    if cont == {}:
        for word in word_list:
            cont[word] = 0
            new_dict[word] = word_list.count(word)

    json_data = r.json()
    data = json_data['data']
    next_page = data['after']
    s_posts = data['children']

    for post in s_posts:
        post_data = post['data']
        title = post_data['title']
        title_words = title.split()
        for w in title_words:
            for key in cont:
                if w.lower() == key.lower():
                    cont[key] += 1

    if next_page is None:
        for key, val in new_dict.items():
            if val > 1:
                cont[key] *= val

        order_dict = sorted(cont.items(), key=lambda x: x[0])
        sorted_res = sorted(order_dict, key=lambda x: (-x[1], x[0]))

        for res in sorted_res:
            if res[1] > 0:
                print('{}: {}'.format(res[0], res[1]))
    else:
        count_words(subreddit, word_list, cont, next_page, new_dict)
