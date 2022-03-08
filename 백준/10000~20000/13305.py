n = int(input())
dist = list(map(int,input().split()))
cost = list(map(int,input().split()))

cur = 0
cur_cost = cost[cur]
answer = 0
for i in dist:
    answer+=cur_cost*i
    cur+=1
    if(cur_cost>cost[cur]):
        cur_cost=cost[cur]
print(answer)
