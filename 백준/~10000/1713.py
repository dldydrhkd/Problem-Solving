import sys

input = sys.stdin.readline

n = int(input())

t = int(input())

rec = [0]*101

li = list(map(int,input().split()))

temp = []
cnt = 0

for i in li:
    check = False
    for j in temp:
        if(j[0]==i):
            check=True
            break
    if(check):
        rec[i]+=1
    else:
        if(len(temp)==n):
            temp1 = []
            for j in range(len(temp)):
                temp1.append((rec[temp[j][0]],temp[j][1]-cnt,temp[j][0]))
            temp1.sort()
            deleted = temp1.pop(0)
            for j in range(len(temp)):
                if temp[j][0]==deleted[2]:
                    del temp[j]
                    break
            rec[deleted[2]]=0
        temp.append((i,cnt))
        rec[i]+=1
    cnt+=1

temp.sort()
answer = []
for i in temp:
    answer.append(str(i[0]))
print(' '.join(answer))