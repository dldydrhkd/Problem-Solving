import sys

input = sys.stdin.readline

def solution(n,li,dp):
    ans = 0
    for i in range(1,n):
        for j in range(i):
            if(li[j]<li[i]):
                dp[i] = max(dp[i],dp[j]+1)
                ans = max(ans,dp[i])
    print(ans+1)
if __name__ == '__main__':
    n = int(input())
    li = list(map(int,input().strip().split()))
    dp = [0]*1010
    solution(n,li,dp)
