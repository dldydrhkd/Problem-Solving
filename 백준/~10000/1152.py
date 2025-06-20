import sys

input = sys.stdin.readline

li = input().split()

cnt = 0
for i in li:
    flag = True
    for j in i:
        if not j.isalpha():
            flag=False
    if flag:
        cnt += 1
print(cnt)