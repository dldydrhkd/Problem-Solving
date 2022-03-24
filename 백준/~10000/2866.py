import sys

input = sys.stdin.readline

r,c = map(int, input().strip().split())

li = [input().strip() for _ in range(r)]

cnt = 0
d = {}
temp = []

for j in range(c):
    s = ''
    for i in range(r):
        s+=li[i][j]
    temp.append(s)
    d[s]=1
cnt = 0
while(True):
    if not temp:
        break
    for i in range(len(temp)):
        s = temp[i][1:]
        temp[i] = s
        if s in d:
            print(cnt)
            quit()
        else:
            d[s] = 1
    cnt+=1
    d={}
print(cnt)