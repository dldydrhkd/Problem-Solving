import sys

input = sys.stdin.readline

n = int(input())
li = [list(map(int,input().strip().split())) for _ in range(n)]

blue_cnt = 0
white_cnt = 0
    

def merge(x,y,l):
    if l==1:
        if li[x][y]==1:
            return 1,1
        else:
            return 0,1
    half = l//2
    dir_x = [0,half,0,half]
    dir_y = [0,0,half,half]
    temp = []
    for i in range(4):
        temp.append(merge(x+dir_x[i],y+dir_y[i],half))
    if temp[0][0]!=-1 and temp[0][0]==temp[1][0] and temp[1][0]==temp[2][0] and temp[2][0]==temp[3][0]:
        if temp[0][0] == 1:
            return 1,1
        else:
            return 0,1
    else:
        for i in range(4):
            if(temp[i][0]==0):
                global white_cnt
                white_cnt+=temp[i][1]
            elif(temp[i][0]==1):
                global blue_cnt
                blue_cnt+=temp[i][1]
        return -1,0
a,b = merge(0,0,n)
if a==0:
    white_cnt+=b
if a ==1:
    blue_cnt += b
print(white_cnt)
print(blue_cnt)