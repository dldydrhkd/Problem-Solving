import sys

input = sys.stdin.readline

n = int(input().strip())
li = list(map(int,input().strip().split()))

d = {}
li.sort()
for i in range(len(li)):
    d[li[i]] = [i,False]

for i in range(len(li)):
    for j in range(i+1,len(li)):
        val = li[i]+li[j]
        if val in d:
            if(d[val][0]==i) or (d[val][0]==j):
                continue
            d[val][1] = True
cnt = 0
for i in li:
    if i in d:
        if d[i][1]:
            cnt+=1
print(cnt)
