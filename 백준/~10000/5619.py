import sys
import heapq

input = sys.stdin.readline
n = int(input().strip())

heap = []

for i in range(n):
    num = int(input().strip())
    heapq.heappush(heap,-num)
    if(len(heap)>=5):
        heapq.heappop(heap)

li = []
while(heap):
    li.append(-heapq.heappop(heap))

answer = []
for i in range(len(li)):
    for j in range(len(li)):
        if(i==j):
            continue
        answer.append(int(str(li[i])+str(li[j])))
answer.sort()
print(answer[2])
