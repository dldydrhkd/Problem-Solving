import sys

input = sys.stdin.readline
sys.setrecursionlimit(10**6)

x = [0,0,-1,1]
y = [1,-1,0,0]
answer = False

def dfs(a,b,li,visited,n,m,st):
    visited[a][b] = True
    for i in range(4):
        nx = a+x[i]
        ny = b+y[i]
        if (0 <= nx < n) and (0 <= ny < m):
            if (visited[nx][ny]) and (li[a][b]==li[nx][ny]):
                if st and not (st[-1][0]==nx and st[-1][1]==ny):
                    global answer
                    answer = True
            elif (not visited[nx][ny]) and (li[a][b]==li[nx][ny]):
                st.append([a,b])
                dfs(nx,ny,li,visited,n,m,st)
                st.pop()


def solution(n,m,li):
    visited = [[False]*m for _ in range(n)]
    for i in range(n):
        for j in range(m):
            if not visited[i][j]:
                st = []
                dfs(i,j,li,visited,n,m,st)
    if answer:
        return 'Yes'
    return 'No'

if __name__ == '__main__':
    n,m = map(int,input().strip().split())
    li = [input().strip() for _ in range(n)]
    print(solution(n,m,li))
    