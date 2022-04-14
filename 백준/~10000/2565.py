import sys

input = sys.stdin.readline

def solution(n,li):
    dp = [0]*101
    ans = 0
    for i in range(n):
        for j in range(i):
            if li[i][1] > li[j][1]:
                dp[i] = max(dp[i],dp[j]+1)
                ans = max(ans,dp[i])
    ans += 1
    print(n-ans)

if __name__ == '__main__':
    n = int(input())
    li = [list(map(int,input().strip().split())) for _  in range(n)]
    li.sort()
    solution(n,li)