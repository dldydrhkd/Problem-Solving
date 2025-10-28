import sys

n,m = map(int,input().split())
li = list(map(int,input().split()))

ans = 0

for i in range(0, len(li)):
    for j in range(i+1, len(li)):
        for k in range(j+1, len(li)):
            if li[i]+li[j]+li[k] <= m:
                ans = max(ans, li[i]+li[j]+li[k])

print(ans)