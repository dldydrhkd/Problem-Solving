import sys

input = sys.stdin.readline


n, k = map(int,input().strip().split())

li = []
sold = 0
for i in range(n):
    a,b = map(int, input().strip().split())
    if a >= b :
        sold +=1
    else:
        li.append(b-a)

li.sort()

if sold>=k:
    print(0)
else:
    print(li[k-sold-1])