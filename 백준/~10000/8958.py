import sys

input = sys.stdin.readline

t = int(input())

while(t):
    t-=1
    s_li = input()
    cnt = 0
    total_cnt = 0
    for s in s_li:
        if s == 'O':
            cnt+=1
            total_cnt+=cnt
        else:
            cnt = 0
    print(total_cnt)
