import sys

input = sys.stdin.readline

n = int(input())

li = []
for i in range(n):
    s = float(input().strip())
    li.append(s)
li.sort()
answer = li[:7]
for i in answer:
    print("{:.3f}".format(i))