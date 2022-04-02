import sys

input = sys.stdin.readline

n = int(input())

li = [int(input()) for _ in range(n)]

li.sort()
for i in range(n):
    print(li[i])
