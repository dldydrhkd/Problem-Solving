import sys

input = sys.stdin.readline

n = int(input())
li = list(map(int,input().strip().split()))
li.sort()
print(li[-1])