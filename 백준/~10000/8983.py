import sys

input = sys.stdin.readline

m,n,l = map(int, input().strip().split())

li_m = list(map(int, input().strip().split()))

li_n = [list(map(int,input().strip().split())) for _ in range(n)]

li_m.sort()
li_n.sort()

def find(min_x, max_x):
    start = 0
    end = len(li_m)-1
    while(start<=end):
        mid = (start+end)//2
        if(li_m[mid]>max_x):
            end = mid-1
        elif(li_m[mid]<min_x):
            start = mid+1
        else:
            return True

cnt = 0
for x,y in li_n:
    if(y>l):
        continue
    temp_len = l-y
    min_x = x - temp_len
    max_x = x + temp_len
    if(find(min_x, max_x)):
        cnt+=1
print(cnt)