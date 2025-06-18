import sys
sys.setrecursionlimit(10**6)

input = sys.stdin.readline

n = int(input())

arr = [0]*50
arr[0] = 0
arr[1] = 1
for i in range(2,50):
    arr[i] = arr[i-1]+arr[i-2]

print(arr[n])