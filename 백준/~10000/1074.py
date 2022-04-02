import sys
import math

input = sys.stdin.readline

n,r,c = map(int,input().strip().split())

def recur(start_x, start_y, l):
    mid_x = start_x + l//2
    mid_y = start_y + l//2
    if(start_x==r and start_y==c):
        return 0
    if(l==1):
        return 0
    cnt = 0
    if(r<mid_x and c<mid_y):
        cnt+=recur(start_x, start_y, l//2)
    elif(r<mid_x and c>=mid_y):
        cnt+=recur(start_x, mid_y, l//2)+(l//2)*(l//2)
    elif(r>=mid_x and c<mid_y):
        cnt+=recur(mid_x, start_y, l//2)+(l//2)*(l//2)*2
    else:
        cnt+=recur(mid_x,mid_y,l//2)+(l//2)*(l//2)*3
    return cnt

answer = recur(0,0,int(math.pow(2,n)))
print(answer)