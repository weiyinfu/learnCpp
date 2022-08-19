from concurrent.futures.thread import ThreadPoolExecutor

import requests
from tqdm import tqdm

"""
实验证明：httplib的server本身就是多线程的，每个请求需要耗时1秒。使用n个进程执行m个请求，耗时m/n，说明httplib是支持多线程的。  

"""


def get(x):
    try:
        resp = requests.get("http://localhost:9978/hi")
        return resp.text
    except:
        return ''


def serial_request():
    for i in range(10):
        print(get(i))


def concurrent_request():
    with ThreadPoolExecutor(max_workers=5) as x:
        total = 50
        res = []
        for i in tqdm(x.map(get, [0] * total), total=total):
            res.append(i)
        valid = len([i for i in res if i])
        print(f'成功率:{valid / len(res)}')


concurrent_request()
