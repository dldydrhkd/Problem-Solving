import sys
from collections import deque
sys.setrecursionlimit(10 ** 6)

n = int(input())

tree = {}

for _ in range(n-1):
    a,b = map(int,input().split())
    if a in tree:
        tree[a].append(b)
    else:
        tree[a] = [b]
    if b in tree:
        tree[b].append(a)
    else:
        tree[b] = [a]

li = [0 for _ in range(n+1)]
visited = [0 for _ in range(n+1)]

dq = deque()
dq.append(1)
visited[1] = True
while(dq):
    size = len(dq)
    for i in range(size):
        parent = dq.popleft()
        if parent in tree:
            for child in tree[parent]:
                if not visited[child]:
                    dq.append(child)
                    li[child] = parent
                    visited[child] = True

for i in range(2, n+1):
    print(li[i])
