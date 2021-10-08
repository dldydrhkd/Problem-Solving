import sys

input = sys.stdin.readline

n,m = map(int,input().split())

li = [0]*100001
for i in range(m):
    temp = list(map(int,input().split()))
    if(temp[0]==1):
        li[temp[1]] = li[temp[1]]|(1<<(temp[2]-1))
    elif(temp[0]==2):
        li[temp[1]] = li[temp[1]]&(~(1<<(temp[2]-1)))
    elif(temp[0]==3):
        li[temp[1]] = (li[temp[1]]<<1)&((1<<20)-1)
    else:
        li[temp[1]] = li[temp[1]]>>1
d = dict()
cnt = 0
for i in range(1,n+1):
    if(li[i] in d):
        continue
    else:
        cnt+=1
        d[li[i]]=1
print(cnt)