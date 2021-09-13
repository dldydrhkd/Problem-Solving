n, l = map(int, input().split())
li = list(map(int,input().split()))
cur_pos = li[0]
cnt = 1
for i in li:
    if(i-cur_pos+1>l):
        cnt+=1
        cur_pos = i

print(cnt)