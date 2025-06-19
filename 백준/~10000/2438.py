import sys

input = sys.stdin.readline

n = int(input())
arr = []
for i in range(n):
    arr.append(['*'*(i+1)])
    print(*arr[i])