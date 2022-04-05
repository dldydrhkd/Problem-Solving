import sys
from collections import deque

input = sys.stdin.readline
sys.setrecursionlimit(10**6)

n,m,v = map(int,input().strip().split())

visited = [False]*(n+1)
node = [set() for _ in range(n+1)]

for i in range(m):
    a,b = map(int,input().strip().split())
    node[a].add(b)
    node[b].add(a)
for i in range(n+1):
    node[i] = sorted(node[i])

dfs_li = []
def dfs(cur):
    visited[cur] = True
    dfs_li.append(str(cur))
    for i in node[cur]:
        if not visited[i]:
            dfs(i)

bfs_li = []
def bfs(cur):
    d = deque()
    visited = [0]*(n+1)
    visited[cur] = True
    bfs_li.append(str(cur))
    d.append(cur)
    while(d):
        front = d.popleft()
        for i in node[front]:
            if not visited[i]:
                visited[i] = True
                bfs_li.append(str(i))
                d.append(i)

dfs(v)
visited = [False]*(n+1)
bfs(v)
print(' '.join(dfs_li))
print(' '.join(bfs_li))