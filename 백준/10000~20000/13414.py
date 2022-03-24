import sys

input = sys.stdin.readline

k,l = map(int, input().strip().split())

d = {}
for i in range(l):
    s = input().strip()
    d[s] = i
li = []
for key,value in d.items():
    li.append([value,key])
li.sort()
i = 0
while(i<len(li) and i<k):
    print(li[i][1])
    i+=1
