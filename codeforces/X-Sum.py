import sys

input = sys.stdin.readline

def check(a,b,n,m):
    if 0 <= a < n and 0 <= b < m:
        return True
    return False
def cal(x,y,li,n,m):
    dir_x = [-1,1,1,-1]
    dir_y = [-1,-1,1,1]
    sum = li[x][y]
    for i in range(4):
        next_x = x+dir_x[i]
        next_y = y+dir_y[i]
        while(check(next_x, next_y,n,m)):
            sum+=li[next_x][next_y]
            next_x = next_x+dir_x[i]
            next_y = next_y+dir_y[i]
    return sum

def solution(n,m,li):
    max_num = 0
    for i in range(n):
        for j in range(m):
            max_num = max(cal(i,j,li,n,m),max_num)
    print(max_num)


if __name__ == '__main__':
    t = int(input().strip())
    for i in range(t):
        n, m = map(int,input().strip().split())
        li = [list(map(int,input().strip().split())) for _ in range(n)]
        solution(n,m,li)