import sys

input = sys.stdin.readline
sys.setrecursionlimit(10**6)

n,k = map(int,input().strip().split())

li = [int(input().strip()) for _ in range(n)]

dp = [-1]*(k+1)

for i in range(len(li)):
    if(li[i]<k+1):
        dp[li[i]] = 1

def func(x):
    if x <= 0:
        return -1
    if dp[x]!=-1:
        return dp[x]
    dp[x] = 999999
    for i in range(len(li)):
        temp = func(x-li[i])
        if(temp==-1):
            continue
        dp[x] = min(func(x-li[i])+1,dp[x])
    return dp[x]

ans = func(k)
if ans==999999:
    print(-1)
else:
    print(ans)