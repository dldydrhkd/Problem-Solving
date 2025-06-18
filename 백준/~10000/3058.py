import sys

input = sys.stdin.readline

t = int(input())

def even_li(li):
    new_li = list(filter(lambda x: x%2==0, li))
    return new_li

def sum_li(li):
    return sum(li)

def min_li(li):
    return min(li)

while(t):
    t-=1
    li = list(map(int, input().split()))
    e_li = even_li(li)
    answer = []
    answer.append(sum_li(e_li))
    answer.append(min_li(e_li))
    print(*answer)
    