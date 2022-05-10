import sys

input = sys.stdin.readline

def solution(t,li):
    li.sort()
    min_num = li[0]
    sum = 0
    for i in range(1,t):
        sum+=li[i]-min_num
    print(sum)
    

if __name__ == '__main__':
    n = int(input().strip())
    for i in range(n):
        t = int(input().strip())
        li = list(map(int,input().strip().split()))
        solution(t,li)