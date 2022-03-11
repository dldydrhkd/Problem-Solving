import sys

input = sys.stdin.readline

n,p = map(int,input().strip().split())

li = [[] for _ in range(7)]
cnt = 0
for i in range(n):
    a,b = map(int, input().strip().split())
    if(li[a]):
        check = False
        while(li[a]):
            if(li[a][-1]>b):
                li[a].pop()
                cnt+=1
            elif(li[a][-1]<b):
                check = True
                li[a].append(b)
                cnt+=1
                break
            else:
                check = True
                break
        if not check:
            li[a].append(b)
            cnt+=1
    else:
        li[a].append(b)
        cnt+=1
print(cnt)