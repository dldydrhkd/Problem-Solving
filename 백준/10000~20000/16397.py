import sys

input = sys.stdin.readline

n,t,g = map(int, input().split())

q = []
q.append(n)

visited = [0]*100000
visited[n] = True
cnt = 0

while(q):
    size = len(q)
    while(size):
        front = q.pop(0)
        if(front==g):
            print(cnt)
            quit()
        if(front+1<=99999 and not visited[front+1]):
            q.append(front+1)
            visited[front+1] = True
        if(front*2<=99999):
            s = str(front*2)
            s = int(s)-10**(len(s)-1)
            if(not visited[s]):
                q.append(s)
                visited[s] = True
        size-=1
    cnt+=1
    if(cnt>t):
        break
print('ANG')
