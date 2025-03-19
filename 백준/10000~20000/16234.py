import sys
sys.setrecursionlimit(100000)
input = sys.stdin.readline

n, l, r = map(int,input().split())
arr = [list(map(int, input().split())) for _ in range(n)]

visited = [[False] * n for _ in range(n)]

def check_range(nx, ny):
    if nx>=0 and ny>=0 and nx<n and ny<n:
        return True
    return False

q = []
dir_x = [0,0,-1,1]
dir_y = [1,-1,0,0]

def dfs(x,y):
    visited[x][y] = True
    q.append((x,y))
    for i in range(4):
        nx = x+dir_x[i]
        ny = y+dir_y[i]
        if check_range(nx,ny) and not visited[nx][ny]:
            if l <= abs(arr[x][y]-arr[nx][ny]) <= r:
                dfs(nx,ny)

ans = 0
while(True):
    visited = [[False] * n for _ in range(n)]
    cont = True
    for i in range(n):
        for j in range(n):
            if not visited[i][j]:
                dfs(i,j)
                cnt = len(q)
                if cnt > 1:
                    cont = False
                sum = 0
                for k in range(len(q)):
                    x = q[k][0]
                    y = q[k][1]
                    sum += arr[x][y]
                while(q):
                    x,y = q.pop(0)
                    arr[x][y] = int(sum/cnt)
    if cont:
        break
    ans +=1 
print(ans)
