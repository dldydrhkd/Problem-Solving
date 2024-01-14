from collections import deque

def solution(land):
    answer = 0
    n = len(land)
    m = len(land[0])
    visited = [[False for j in range(m)] for i in range(n)]
    res = [0 for i in range(m+1)]
    dx = [0,0,-1,1]
    dy = [-1,1,0,0]
    def check(x, y):
        if 0 <= x and x < n and 0 <= y and y < m :
            return True
        return False
    dq = deque()
    def bfs(x,y):
        visited[x][y] = True
        dq.append((x,y))
        min_y = y
        max_y = y
        cnt = 0
        while(dq):
            now = dq.popleft()
            a = now[0]
            b = now[1]
            min_y = min(min_y, b)
            max_y = max(max_y, b)
            cnt+=1
            for i in range(4):
                nx = a + dx[i]
                ny = b + dy[i]
                if check(nx,ny) and land[nx][ny] and not visited[nx][ny]:
                    visited[nx][ny] = True
                    dq.append((nx,ny))
        for i in range(min_y, max_y+1):
            res[i]+=cnt
            
    for i in range(n):
        for j in range(m):
            if not visited[i][j] and land[i][j]:
                bfs(i,j)
    answer = max(res)
    return answer
