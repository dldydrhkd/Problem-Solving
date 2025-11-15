import sys
from collections import deque
sys.setrecursionlimit(10**6)

input = sys.stdin.readline

n,m = map(int,input().split())

arr = []
visited = [[False]*m for _ in range(n)]

for _ in range(n):
    li = list(map(int, input().strip()))
    arr.append(li)

dq = deque()
dq.append([0,0])
visited[0][0] = True
dir_x = [0, 0, -1, 1]
dir_y = [1, -1, 0, 0]

def check(x, y):
    if x>=0 and y>=0 and x<n and y<m:
        return True
    return False

cnt = 0

while(dq):
    size = len(dq)
    cnt+=1
    while(size):
        size-=1
        top = dq.popleft()
        x, y = top[0], top[1]
        if x==n-1 and y==m-1:
            print(cnt)
            sys.exit()
        for i in range(4):
            nx = x+dir_x[i]
            ny = y+dir_y[i]
            if check(nx,ny) and not visited[nx][ny] and arr[nx][ny]==1:
                dq.append([nx,ny])
                visited[nx][ny] = True