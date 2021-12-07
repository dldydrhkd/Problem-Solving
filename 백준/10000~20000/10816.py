import sys

input = sys.stdin.readline

n = int(input())
li1 = list(map(int,input().strip().split()))
m = {}
for i in li1:
    if(i in m):
        m[i]+=1
    else:
        m[i] = 1
k = int(input())
li2 = list(map(int,input().strip().split()))
answer = []
for j in li2:
    if(j in m):
        answer.append(str(m[j]))
    else:
        answer.append(str(0))
print(' '.join(answer))
    