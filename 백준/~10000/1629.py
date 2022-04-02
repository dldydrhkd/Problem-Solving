import sys
import math

input = sys.stdin.readline

a,b,c = map(int, input().strip().split())

def my_pow(x,y):
    if y==0:
        return 1
    temp = my_pow(x,y//2)
    if y%2==0:
        return temp*temp % c
    else:
        return temp*temp*x % c

print(my_pow(a,b))