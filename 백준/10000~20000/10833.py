import sys

input = sys.stdin.readline

n = int(input())

t_sum = 0
while(n):
    n-=1
    student, apple = map(int,input().split())
    t_sum += apple%student

print(t_sum)