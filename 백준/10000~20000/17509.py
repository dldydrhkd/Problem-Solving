li = []*11
for _ in range(0,11):
    d,v= map(int,input().split())
    li.append((d,v))
li.sort()
pen = 0
cnt = 0
for i in li:
    pen += cnt + i[0]
    cnt += i[0]
for i in li:
    pen += (20*i[1])
print(pen)
    