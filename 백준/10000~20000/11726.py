import sys

input = sys.stdin.readline

n = int(input())

arr = [[0]*2 for _ in range(10001)]

arr[1][0] = 1
arr[2][0] = 1
arr[2][1] = 1

for i in range(3,n+1):
    arr[i][0] = arr[i-1][0]+arr[i-1][1]
    arr[i][0] %= 10007
    arr[i][1] = arr[i-2][0]+arr[i-2][1]
    arr[i][1] %= 10007

print((arr[n][0]+arr[n][1])%10007)
