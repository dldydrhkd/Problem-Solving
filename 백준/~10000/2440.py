import sys

input = sys.stdin.readline

n = int(input())
for i in range(n):
    arr = []
    for j in range(n-i):
        arr.append('*')
    print(''.join(arr))