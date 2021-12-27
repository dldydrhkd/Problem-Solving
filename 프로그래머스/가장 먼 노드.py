def solution(n, edge):
    answer = 0
    info = [[] for _ in range(n+1)]
    for a,b in edge:
        info[a].append(b)
        info[b].append(a)
    visited = [-1]*(n+1)
    q = []
    visited[1]=0
    q.append(1)
    cnt = 0
    while(q):
        size = len(q)
        cnt+=1
        while(size):
            front = q.pop(0)
            for i in range(len(info[front])):
                next = info[front][i]
                if(visited[next]==-1):
                    visited[next]=cnt
                    q.append(next)
            size-=1
    visited.sort()
    visited = visited[::-1]
    max_cnt = visited[0]
    answer+=1
    for i in range(1,len(visited)):
        if(visited[i]==max_cnt):
            answer+=1
        else:
            break
    return answer