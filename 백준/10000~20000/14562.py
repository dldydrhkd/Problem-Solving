import sys

input = sys.stdin.readline

c = int(input())

while(c):
    c-=1
    s,t = map(int, input().split())
    cnt = 0
    li = []
    visited = [False for _ in range(1001)]
    visited[s]=True
    li.append((s,t))
    check = False
    while(li):
        if(check):
            break
        li_len = len(li)
        while(li_len):
            if(check):
                break
            li_len -= 1
            n_s, n_t = li.pop(0)
            if(n_s==n_t):
                print(cnt)
                check = True
            else:
                if(not visited[n_s+1]):
                    li.append((n_s+1,n_t))
                    visited[n_s+1] = True
                if((not visited[n_s*2]) and (n_s*2<=n_t+3)):
                    li.append((n_s*2,n_t+3))
                    visited[n_s*2] = True
        cnt+=1
