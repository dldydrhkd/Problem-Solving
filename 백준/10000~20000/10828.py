import sys
from collections import deque

input = sys.stdin.readline

n = int(input())

deq = deque()

while(n):
    n-=1
    cmd = input().split()
    if(cmd[0]=='push'):
        deq.append(int(cmd[1]))
    if(cmd[0]=='top'):
        if(deq):
            print(deq[-1])
        else:
            print(-1)
    if(cmd[0]=='size'):
        print(len(deq))
    if(cmd[0]=='empty'):
        if(deq):
            print(0)
        else:
            print(1)
    if(cmd[0]=='pop'):
        if(deq):
            pop_num = deq.pop()
            print(pop_num)
        else:
            print(-1)