import sys

input = sys.stdin.readline

n,k = map(int,input().split())

n = str(n)
visited = [False]*1000001
q = []
q.append(n)
while(q and k):
    c = set()
    size = len(q)
    answer = -1
    while(size):
        front = q.pop(0)
        for i in range(len(front)):
            for j in range(i+1,len(front)):
                temp = ''
                for l in range(len(front)):
                    if(l==i):
                        temp+=front[j]
                    elif(l==j):
                        temp+=front[i]
                    else:
                        temp+=front[l]
                if(temp[0]=='0'):
                    continue
                if temp not in c:
                    answer = max(answer, int(temp))
                    c.add(temp)
                    q.append(temp)
        size-=1
    k-=1
print(answer)