import sys
from collections import deque

input = sys.stdin.readline

n,m = map(int,input().split())

visited = [False] * (n+1)

def backtrack(dq):
    if len(dq) == m:
        print(*list(dq))
        return
    for i in range(1,n+1):
        if not visited[i]:
            dq.append(i)
            visited[i] = True
            backtrack(dq)
            visited[i] = False
            dq.pop()
    return
    

for i in range(1, n+1):
    dq = deque()
    dq.append(i)
    visited[i] = True
    backtrack(dq)
    visited[i] = False