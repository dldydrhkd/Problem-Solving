import sys
import heapq
from collections import deque

input = sys.stdin.readline

n = int(input().strip())
li = [list(map(int,input().strip().split())) for _ in range(n)]
d = int(input().strip())
for i in li:
    if(i[0]>i[1]):
        i[0],i[1] = i[1],i[0]

li.sort(key = lambda x : (x[1],x[0]))

heap = []

cnt = 0
for i in range(len(li)):
    x = li[i][0]
    y = li[i][1]
    if(y-x>d):
        continue
    heapq.heappush(heap,x)
    while(heap and heap[0]<y-d):
        heapq.heappop(heap)
    cnt = max(cnt, len(heap))
print(cnt)