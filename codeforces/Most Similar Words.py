import sys

input = sys.stdin.readline

def difference(a,b):
    sum = 0
    for i in range(len(a)):
        sum+=abs(ord(a[i])-ord(b[i]))
    return sum

def solution(n,m,li):
    min_num = 987654321
    for i in range(n):
        for j in range(i+1,n):
            a = li[i]
            b = li[j]
            min_num = min(difference(a,b),min_num)
    print(min_num)


if __name__ == '__main__':
    t = int(input().strip())
    for i in range(t):
        n, m = map(int,input().strip().split())
        li = [input().strip() for _ in range(n)]
        solution(n,m,li)