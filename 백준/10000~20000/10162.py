import sys

input = sys.stdin.readline

a = 0
b = 0
c = 0

t = int(input().strip())

while(t>=300):
    a+=1
    t-=300
while(t>=60):
    b+=1
    t-=60
while(t>=10):
    c+=1
    t-=10
if(t==0):
    li = []
    li.append(str(a))
    li.append(str(b))
    li.append(str(c))
    print(' '.join(li))
else:
    print(-1)