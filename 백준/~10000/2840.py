import sys
from collections import deque

input = sys.stdin.readline

n, k = map(int, input().strip().split())

query = []

for i in range(k):
    cnt, alpha = input().strip().split()
    cnt = int(cnt)
    query.append([cnt,alpha])

d = deque()

for i in range(n):
    d.append([i,0])

for i in range(k):
    cnt = query[i][0]
    alpha = query[i][1]
    for j in range(cnt):
        d.rotate(-1)
    if(d[0][1]==0):
        d[0][1] = alpha
    else:
        if(d[0][1]!=alpha):
            print('!')
            quit()
alpha_li = [False]*26
for i in range(n):
    if(d[0][1]!=0):
        if(alpha_li[ord(d[0][1])-ord('A')]):
            print('!')
            quit()
        else:
            alpha_li[ord(d[0][1])-ord('A')]=True
    d.rotate(-1)
answer = []
for i in range(n):
    if(d[0][1]==0):
        answer.append('?')
    else:
        answer.append(d[0][1])
    d.rotate(1)
print(''.join(answer))