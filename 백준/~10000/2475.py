import sys

input = sys.stdin.readline

line = map(int, input().split())

t_sum = 0
for i in line:
    t_sum += i**2

print(t_sum%10)