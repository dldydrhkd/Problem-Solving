import sys

input = sys.stdin.readline

n,m = map(int, input().split())

li = [list(map(int, input().split())) for _ in range(n)]

k = int(input())

acc = [[0 for _ in range(301)] for _ in range(301)]

for i in range(n):
    for j in range(m):
        acc[i+1][j+1] = acc[i][j+1] + acc[i+1][j] - acc[i][j] + li[i][j]

while(k):
    k-=1
    i,j,x,y = map(int,input().split())
    print(acc[x][y]-acc[i-1][y]-acc[x][j-1]+acc[i-1][j-1])
    

