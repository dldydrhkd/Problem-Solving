import sys

input = sys.stdin.readline

a = int(input())
b = int(input())
c = int(input())

d = str(a*b*c)
di = {i: 0 for i in range(10)}

for ch in d:
    di[int(ch)] += 1

for i in range(10):
    print(di[i])