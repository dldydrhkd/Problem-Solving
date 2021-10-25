import sys

input = sys.stdin.readline

x, y = map(int,input().split())

z = y*100//x

start = 1
end = 1000000000

answer = 1000000000

check = False

while(start<=end):
    mid = (start+end)//2
    if(x+mid>2000000000):
        end = mid-1
    elif((y+mid)*100//(x+mid) != z):
        answer = min(answer,mid)
        end = mid-1
        check = True
    else:
        start = mid+1

if(check):
    print(answer)
else:
    print(-1)