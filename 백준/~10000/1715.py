import sys
sys.setrecursionlimit(10**9)

input = sys.stdin.readline

n = int(input())
li = []
for i in range(n):
    li.append(int(input()))

li.sort()

print(li)