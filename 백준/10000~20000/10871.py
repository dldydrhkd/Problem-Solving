import sys

input = sys.stdin.readline

n, l = map(int, input().split())

li = list(map(int,input().split()))

new_li = list(filter(lambda x : x<l, li))

print(*new_li)