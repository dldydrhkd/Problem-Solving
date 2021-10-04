import sys
from queue import PriorityQueue
import heapq

input = sys.stdin.readline

t = int(input())

for i in range(t):
    k = int(input())
    min_pq, max_pq = [],[]
    min_cnt = 0
    max_cnt = 0
    visited = [0]*1000001
    for j in range(k):
        l,n = input().split()
        n = int(n)
        if(l=='I'):
            heapq.heappush(min_pq, (n,j))
            heapq.heappush(max_pq, (-n,j)) 
            visited[j]=True
        else:
            if(n==1):
                while(max_pq and not visited[max_pq[0][1]]):
                    heapq.heappop(max_pq)
                if(max_pq):
                    visited[max_pq[0][1]] = False
                    heapq.heappop(max_pq)
            else:
                while(min_pq and not visited[min_pq[0][1]]):
                    heapq.heappop(min_pq)
                if(min_pq):
                    visited[min_pq[0][1]] = False
                    heapq.heappop(min_pq)
    while(max_pq and not visited[max_pq[0][1]]):
        heapq.heappop(max_pq)
    while(min_pq and not visited[min_pq[0][1]]):
        heapq.heappop(min_pq)
    if(not min_pq and not max_pq):
        print("EMPTY")
    else:
        print(-max_pq[0][0], min_pq[0][0])