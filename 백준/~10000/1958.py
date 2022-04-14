import sys

input = sys.stdin.readline

def solution(li):
    dp = [[[0]*101 for _ in range(101)] for _ in range(101)]
    for i in range(1,len(li[0])+1):
        for j in range(1,len(li[1])+1):
            for k in range(1,len(li[2])+1):
                if li[0][i-1]==li[1][j-1] and li[1][j-1]==li[2][k-1]:
                    dp[i][j][k] = dp[i-1][j-1][k-1]+1
                else:
                    dp[i][j][k] = max(dp[i-1][j][k],dp[i][j-1][k],dp[i][j][k-1])
    print(dp[len(li[0])][len(li[1])][len(li[2])])
if __name__ == '__main__':
    n = 3
    li = [input().strip() for _  in range(3)]
    solution(li)