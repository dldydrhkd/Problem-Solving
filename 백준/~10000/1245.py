from re import I
import sys

input = sys.stdin.readline
sys.setrecursionlimit(10**6)

is_mountain = False

x = [0,0,-1,1,1,1,-1,-1]
y = [-1,1,0,0,1,-1,-1,1]

def check(a,b,n,m):
    if a>=0 and a<n and b>=0 and b<m:
        return True
    return False

def dfs(li,a,b,visited,n,m):
    visited[a][b] = True
    for i in range(8):
        nx = a + x[i]
        ny = b + y[i]
        if(check(nx,ny,n,m) and li[a][b]<li[nx][ny]):
            global is_mountain
            is_mountain = False
        if check(nx,ny,n,m) and not visited[nx][ny] and li[nx][ny]:
            if(li[nx][ny]==li[a][b]):
                dfs(li,nx,ny,visited,n,m)

def solution(n,m,li):
    visited = [[False]*m for _ in range(n)]
    cnt = 0
    for i in range(n):
        for j in range(m):
            if not visited[i][j] and li[i][j]:
                global is_mountain
                is_mountain = True
                dfs(li,i,j,visited,n,m)
                if(is_mountain):
                    cnt+=1
    return cnt
    

if __name__ == "__main__":
    n,m = map(int,input().strip().split())
    li = [list(map(int,input().strip().split())) for _ in range(n)]
    print(solution(n,m,li))