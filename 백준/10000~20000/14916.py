import sys

input = sys.stdin.readline

n = int(input())

li = [-1 for i in range(100001)]
li[0] = 0
x = [5,2]

for i in range(1,n+1):
    if li[i-x[0]] >= 0 and li[i-x[1]] >= 0:
        li[i] = min(li[i-x[0]], li[i-x[1]])+1
    elif li[i-x[0]] >= 0:
        li[i] = li[i-x[0]]+1
    elif li[i-x[1]] >= 0:
        li[i] = li[i-x[1]]+1

print(li[n])