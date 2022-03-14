import sys
from collections import deque

input = sys.stdin.readline

n = int(input().strip())
k = int(input().strip())

arr = [[False]*(n+2) for _ in range(n+2)] 
for i in range(k):
    a,b = map(int,input().strip().split())
    arr[a][b] = True

l = int(input().strip())

move = [list(input().strip().split()) for _ in range(l)]

d = deque([[1,1]])
x = [0,1,0,-1]
y = [1,0,-1,0]
cur_x = 1
cur_y = 1
cur_t = 0
cur_dir = 0

def collision(a,b):
    if(a>=1 and a<=n and b>=1 and b<=n):
        return False
    return True

for m in move:
    t = int(m[0])
    turn = m[1]
    while(cur_t!=t):
        cur_x += x[(cur_dir)%4]
        cur_y += y[(cur_dir)%4]
        if(collision(cur_x,cur_y)):
            print(cur_t+1)
            quit()
        for i in d:
            if(i==[cur_x,cur_y]):
                print(cur_t+1)
                quit()
        d.appendleft([cur_x,cur_y])
        if(arr[cur_x][cur_y]):
            arr[cur_x][cur_y] = False
        else:
            d.pop()
        cur_t+=1
    if(turn=='L'):
        cur_dir-=1
    else:
        cur_dir+=1
while(True):
    cur_x += x[(cur_dir)%4]
    cur_y += y[(cur_dir)%4]
    if(collision(cur_x,cur_y)):
        print(cur_t+1)
        quit()
    for i in d:
        if(i==[cur_x,cur_y]):
            print(cur_t+1)
            quit()
    d.appendleft([cur_x,cur_y])
    if(arr[cur_x][cur_y]):
        arr[cur_x][cur_y] = False
    else:
        d.pop()
    cur_t+=1