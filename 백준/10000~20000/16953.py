import sys
from collections import deque
import heapq

input = sys.stdin.readline

a, b = map(int, input().split())

q = deque([(a,1)])

while(q):
    tmp,cnt = q.popleft()

    if tmp == b:
        print(cnt)
        exit()
    tmp1 = tmp*2
    tmp2 = tmp*10 + 1
    
    if tmp1 <= b:
        q.append((tmp1, cnt+1))
    if tmp2 <= b:
        q.append((tmp2, cnt+1))
print(-1)