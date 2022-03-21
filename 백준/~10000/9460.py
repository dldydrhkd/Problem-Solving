import sys

input = sys.stdin.readline

t = int(input().strip())

def check(max_len,temp_l,temp_k):
    low_pos = temp_l[0][1]
    high_pos = temp_l[0][1]
    cnt_k = 1
    for i in range(len(temp_l)):
        y = temp_l[i][1]
        low_pos = min(low_pos,y)
        high_pos = max(high_pos,y)
        length = high_pos-low_pos
        if(length>max_len):
            low_pos = y
            high_pos = y
            cnt_k += 1
    if(temp_k>=cnt_k):
        return True
    return False




while(t):
    n,k = map(int,input().strip().split())
    li = list(map(int,input().strip().split()))
    l = [[li[x],li[x+1]] for x in range(0,len(li),2)]
    l.sort()
    start = 0
    end = 200000000
    answer = 200000000.0
    while(start<=end):
        mid = (start+end)//2
        if(check(mid,l,k)):
            answer = min(answer, mid)
            end = mid-1
        else:
            start = mid+1
    print(round(answer/2,1))
    t-=1


