import heapq

def solution(N, road, K):
    answer = 0
    
    info = [[5000000]*51 for _ in range(51)]
    visited = [5000000]*51
    
    for i in range(len(road)):
        info[road[i][0]][road[i][1]]=min(road[i][2],info[road[i][0]][road[i][1]])
        info[road[i][1]][road[i][0]]=min(road[i][2],info[road[i][1]][road[i][0]])
    
    heap = []
    visited[1]=0
    heapq.heappush(heap,[0,1])
    while(heap):
        value,node = heapq.heappop(heap)
        for i in range(1,N+1):
            if(value+info[node][i]<visited[i] and value+info[node][i]<=K):
                heapq.heappush(heap,[value+info[node][i],i])
                visited[i] = value+info[node][i]
    for i in range(1,N+1):
        if(visited[i]<=K):
            answer+=1
    return answer