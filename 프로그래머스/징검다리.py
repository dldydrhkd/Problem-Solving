def check(mid, distance, rocks, n):
    cur = 0
    cut = 0
    for i in rocks:
        if(i-cur>=mid):
            cur = i
        else:
            cut+=1
    if(distance-cur<mid):
        cur+=1
    if(cut<=n):
        return True
    else:
        return False

def solution(distance, rocks, n):
    answer = 0
    rocks.sort()
    start = 0
    end = distance
    while(start<=end):
        mid = (start+end)//2
        if(check(mid, distance, rocks, n)):
            start = mid+1
            answer = mid
        else:
            end = mid-1
    return answer