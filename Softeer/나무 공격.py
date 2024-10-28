import sys

n,m = map(int, input().split())

answer = 0
li = [0 for i in range(n)]
for i in range(n):
    tmp_li = list(map(int, input().split()))
    for j in range(len(tmp_li)):
        if tmp_li[j] == 1:
            li[i]+=1

a,b = map(int, input().split())
for i in range(a-1, b):
    li[i]-=1
c,d = map(int, input().split())
for i in range(c-1, d):
    li[i]-=1
for i in range(n):
    if li[i]>0:
        answer+=li[i]

print(answer)