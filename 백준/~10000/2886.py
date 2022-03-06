import sys
import math

input = sys.stdin.readline

r,c = map(int, input().split())

li = [input() for _ in range(r)]

l = []
x = []

for i in range(r):
    for j in range(c):
        if li[i][j]=='L':
            l.append((i,j))
        elif li[i][j]=='X':
            x.append((i,j))

cnt = 101
visited = [[False]*101 for i in range(101)]
answer = 0

while(cnt):
    cnt-=1
    l_len = len(l)
    x_len = len(x)
    cost = [[[] for _ in range(c)] for _ in range(r)]
    for i in range(r):
        for j in range(c):
            if(li[i][j]=='X'):
                for k in range(len(l)):
                    cur_x = l[k][0]
                    cur_y = l[k][1]
                    if(visited[cur_x][cur_y]):
                        continue
                    dist = (cur_x-i)**2 + (cur_y-j)**2
                    dist = math.sqrt(dist)
                    cost[i][j].append((cur_x,cur_y,dist))
            elif(li[i][j]=='L'):
                for k in range(len(x)):
                    cur_x = x[k][0]
                    cur_y = x[k][1]
                    if(visited[cur_x][cur_y]):
                        continue
                    dist = (cur_x-i)**2 + (cur_y-j)**2
                    dist = math.sqrt(dist)
                    cost[i][j].append((cur_x,cur_y,dist))
    for i in range(r):
        for j in range(c):
            if(cost[i][j]):
                cost[i][j].sort(key = lambda x : x[2])
    for i in range(r):
        for j in range(c):
            if(li[i][j]=='L' and cost[i][j] and (not visited[i][j])):
                top_dist = cost[i][j][0][2]
                c_x = cost[i][j][0][0]
                c_y = cost[i][j][0][1]
                if(cost[c_x][c_y][0][2]!=top_dist):
                    continue
                collision = False

                for k in range(1,len(cost[i][j])):
                    if(cost[i][j][k][2]==top_dist):
                        cur_x = cost[i][j][k][0]
                        cur_y = cost[i][j][k][1]
                        if(cost[cur_x][cur_y][0][0]==i and cost[cur_x][cur_y][0][1]==j):
                            collision = True
                            visited[cur_x][cur_y]=True
                    else:
                        break
                visited[i][j] = True
                visited[c_x][c_y] = True
                if(collision):
                    answer+=1
print(answer)
