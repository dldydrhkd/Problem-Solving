import sys
sys.setrecursionlimit(10**9)
input = sys.stdin.readline

max_num = 100000000

n = int(input())
arr = [max_num]*5001
arr[3] = 1
arr[5] = 1
arr[6] = 2
arr[7] = max_num

for i in range(8,5001):
    arr[i] = min(arr[i-5]+1, arr[i-3]+1)


if arr[n] == max_num:
    print(-1)
else:
    print(arr[n])