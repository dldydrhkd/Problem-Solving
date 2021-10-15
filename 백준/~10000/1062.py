import sys
from itertools import combinations

input = sys.stdin.readline

n,k = map(int, input().split())

li = []

for _ in range(n):
    s = input().strip()
    li.append(s[4:-4])

visited = [0]*26

if(k<5):
    print(0)
    quit()

comb = combinations('bdefghjklmopqrsuvwxyz',k-5)

for j in 'antic':
    visited[ord(j)-ord('a')]=True

cnt = 0
ans = 0

for i in li:
    temp = 0
    for j in i:
        if(visited[ord(j)-ord('a')]):
            temp+=1
    if(temp==len(i)):
        cnt+=1

ans = max(ans,cnt)

for i in comb:
    for j in i:
        visited[ord(j)-ord('a')]=True
    cnt = 0
    for j in li:
        temp = 0
        for f in j:
            if(visited[ord(f)-ord('a')]):
                temp+=1
        if(temp==len(j)):
            cnt+=1
    ans = max(cnt,ans)
    for j in i:
        visited[ord(j)-ord('a')]=False

print(max(ans,cnt))