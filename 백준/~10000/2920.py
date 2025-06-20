import sys

input = sys.stdin.readline

t = int(input())

while(t):
    t-=1
    r, p = input().split()
    r = int(r)
    li = []
    for i in p:
        li.append(i*r)
    print(''.join(li))