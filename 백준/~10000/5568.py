import sys

input = sys.stdin.readline

n = int(input().strip())

k = int(input().strip())

li = []
visited = [False]*n
for i in range(n):
    s = input().strip()
    li.append(s)

dic = {}
def comb(st, cnt):
    if(cnt==0):
        dic[st] = 1
        return
    for j in range(len(visited)):
        if not visited[j]:
            visited[j] = True
            comb(st+li[j],cnt-1)
            visited[j] = False
comb('',k)
print(len(dic))
