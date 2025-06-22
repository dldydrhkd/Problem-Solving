import sys
from collections import deque

input = sys.stdin.readline

n = int(input())
d = deque()
while(n):
    n-=1
    line = input().split()
    order = line[0]
    if order == 'push':
        num = int(line[1])
        d.append(num)
    elif order == 'front':
        if(d): print(d[0])
        else: print(-1)
    elif order == 'back':
        if(d): print(d[len(d)-1])
        else: print(-1)
    elif order == 'size':
        print(len(d))
    elif order == 'empty':
        if d : print(0)
        else : print(1)
    elif order == 'pop':
        if(d):
            a = d.popleft()
            print(a)
        else:
            print(-1)
    