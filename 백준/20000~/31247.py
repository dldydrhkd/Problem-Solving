import sys
import math

input = sys.stdin.readline

t = int(input())

def is_odd(num):
    return True if num%2==1 else False

def cnt(num):
    cnt_num = 0
    while(num != 1):
        num //= 2
        cnt_num+=1
    return cnt_num

while(t):
    t-=1
    n, k = map(int, input().split())
    odd = n//2 + 1
    even = n//2

    if k == 0:
        if is_odd(n):
            print(odd)
        else:
            print(even)
    elif k == 1:
        print(cnt(n))
    elif k == 2:
        if is_odd(n):
            print(n-odd-cnt(n))
        else:
            print(n-even-cnt(n))
    else :
        print(0)

1 -> 0
2 -> 1
3 -> 0
4 -> 2
5 -> 1
6 -> 1
7 -> 0
8 -> 3
9 -> 0
10 -> 1
11 -> 0
12 -> 1
13 -> 0
14 -> 1
15 -> 0
16 -> 4 
    
