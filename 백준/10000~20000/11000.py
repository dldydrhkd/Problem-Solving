from queue import PriorityQueue
import sys

input = sys.stdin.readline
N = int(input())
li = [list(map(int, input().split())) for _ in range(N)]
li.sort()

pq = PriorityQueue()
pq.put(li[0][1])

for i in range(1, len(li)):
    start, end = li[i]
    temp_end = pq.get()
    if(temp_end <= start):
        pq.put(end)
    else:
        pq.put(temp_end)
        pq.put(end)

print(pq.qsize())