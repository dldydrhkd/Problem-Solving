import sys

input = sys.stdin.readline

n, m = map(int, input().split())
t = n
li = []
while(t):
    t-=1
    tmp_num = int(input())
    li.append(tmp_num)

def func(num):
    cnt = 1
    money = num
    for cost in li:
        if num < cost:
            return False
        if money < cost:
            money = num
            cnt += 1
        money -= cost
    return cnt <= m

start = max(li)
end = sum(li)
ans = end
while(start<=end):
    mid = (start+end)//2
    if func(mid):
        ans = min(mid, ans)
        end = mid-1
    else:
        start = mid+1

print(ans)