def solution(n, computers):
    cnt = 0
    li = computers
    visited = [False for _ in range(n)]
    
    def dfs(node):
        visited[node] = True
        for i in range(n):
            if (not visited[i]) and (li[node][i]):
                dfs(i)
            
    for i in range(n):
        if visited[i]==False:
            dfs(i)
            cnt+=1
    return cnt
