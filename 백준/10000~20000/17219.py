import sys

input = sys.stdin.readline

n, m = map(int, input().strip().split())

dic = {}

for i in range(n):
    url, pwd = input().strip().split()
    dic[url] = pwd

for i in range(m):
    url = input().strip()
    print(dic[url])
