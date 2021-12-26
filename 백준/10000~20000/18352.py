import sys

input = sys.stdin.readline

n,m,k,x = map(int,input().strip().split())

li = [[] for i in range(n+1)]
visited = [-1]*(n+1)

for i in range(m):
    a, b = map(int, input().strip().split())
    li[a].append(b)

q = []
cnt = 0
q.append(x)
visited[x] = 0
answer = []
while(q):
    size = len(q)
    cnt+=1
    while(size):
        front = q.pop(0)
        for i in range(len(li[front])):
            next = li[front][i]
            if(cnt<=k and visited[next]==-1):
                q.append(next)
                visited[next] = cnt
        size-=1

for i in range(n+1):
    if(visited[i]==k):
        answer.append(str(i))

if(answer):
    print(' '.join(answer))
else:
    print(-1)
