import sys

input = sys.stdin.readline

def solution(n,k,li):
    li.sort()
    l = 0
    r = -1
    cur_front = li[0]
    cur = li[0]
    cur_back = 0
    cur_cnt = 1
    for i in range(1,len(li)):
        if li[i]==li[i-1]:
            cur_cnt+=1
        else:
            if cur_cnt>=k:
                cur_back = cur
            cur = li[i]
            if r-l < cur_back - cur_front:
                r = cur_back
                l = cur_front
            if cur_cnt<k:
                cur_front = cur
            if li[i]-1!=li[i-1]:
                cur_front = li[i]
            cur = li[i]
            cur_cnt = 1
    if cur_cnt>=k:
        cur_back = cur
    if r-l < cur_back - cur_front:
        r = cur_back
        l = cur_front
    if r==-1:
        print(-1)
    else:
        print(l,r)

if __name__ == '__main__':
    t = int(input().strip())
    for i in range(t):
        n,k = map(int,input().strip().split())
        li = list(map(int,input().strip().split()))
        solution(n,k,li)


