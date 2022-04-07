import sys
sys.setrecursionlimit(10**6)

input = sys.stdin.readline

x = [0,0,-1,1]
y = [-1,1,0,0]

def check(a,b,m,n):
    if a>=0 and a<m and b>=0 and b<n:
        return True
    return False

def dfs(cur_x, cur_y, visited, arr, m,n):
    visited[cur_x][cur_y] = True
    for i in range(4):
        next_x = cur_x + x[i]
        next_y = cur_y + y[i]
        if check(next_x,next_y,m,n) and not visited[next_x][next_y] and arr[next_x][next_y]=='0':
            dfs(next_x, next_y, visited, arr, m,n)

def solution(m,n,arr):
    answer = "NO"
    visited = [[False]*n for _ in range(m)]
    for j in range(n):
        if not visited[0][j]:
            dfs(0,j,visited,arr,m,n)
    for j in range(n):
        if visited[m-1][j]:
            answer = "YES"
            break
    return answer

if __name__=="__main__":
    m,n = map(int,input().strip().split())
    arr = [list(input().strip()) for _ in range(m)]
    print(solution(m,n,arr))