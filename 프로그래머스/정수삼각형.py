def solution(triangle):
    dp = [[0]*501 for _ in range(501)]
    for i in range(0, len(triangle)):
        for j in range(0, len(triangle[i])):
            dp[i][j] = triangle[i][j]
    for i in range(len(triangle)-1):
        for j in range(len(triangle[i])):
            dp[i+1][j] = max(dp[i+1][j],triangle[i+1][j]+dp[i][j])
            dp[i+1][j+1] = max(dp[i+1][j+1], triangle[i+1][j+1]+dp[i][j])
    answer = 0
    for j in range(len(triangle[len(triangle)-1])):
        answer = max(dp[len(triangle)-1][j],answer)
    return answer