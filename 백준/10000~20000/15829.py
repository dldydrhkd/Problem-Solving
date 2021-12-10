import sys

input = sys.stdin.readline

l = int(input().strip())

s = input().strip()

alpha = 'abcdefghijklmnopqrstuvwxyz'

answer = 0

for i in range(l):
    idx = alpha.index(s[i])+1
    answer += idx * (31 ** i)
    answer %= 1234567891

print(answer)