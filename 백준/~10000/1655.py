import sys
import heapq

input = sys.stdin.readline
n = int(input().strip())

low = []
high = []
for i in range(n):
    num = int(input().strip())
    if(not low):
        heapq.heappush(low,-num)
        print(-low[0])
        continue
    if(len(low)<=len(high)):
        heapq.heappush(low,-num)
    else:
        heapq.heappush(high,num)
    while(low and high):
        if(-low[0]<=high[0]):
            break
        l = -heapq.heappop(low)
        h = heapq.heappop(high)
        heapq.heappush(low,-h)
        heapq.heappush(high, l)
    print(-low[0])