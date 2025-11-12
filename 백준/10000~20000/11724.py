from collections import deque

n,m = map(int, input().split())

tree = {}
visited = [False for _ in range(n+1)]

for _ in range(m):
    a,b = map(int,input().split())
    if a in tree:
        tree[a].append(b)
    else:
        tree[a] = [b]
    
    if b in tree:
        tree[b].append(a)
    else:
        tree[b] = [a]

cnt = 0

for i in range(1,n+1):
    dq = deque()
    if not visited[i]:
        dq.append(i)
        visited[i] = True
        cnt+=1
        while(dq):
            size = len(dq)
            for _ in range(size):
                top = dq.popleft()
                children = tree[top]
                for child in children:
                    if not visited[child]:
                        dq.append(child)
                        visited[child] = True


print(cnt)