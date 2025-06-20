import sys

input = sys.stdin.readline

n = int(input())
for i in range(n):
    arr = []
    for j in range(n-i-1):
        arr.append(' ')
    for j in range(i+1):
        arr.append('*')
    print(''.join(arr))