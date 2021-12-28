def solution(n, lost, reserve):
    answer = 0
    info = [1]*(n+1)
    for i in reserve:
        info[i]+=1
    for i in lost:
        info[i]-=1
    for i in range(1,n+1):
        if(i-1>0 and info[i-1]==0 and info[i]>=2):
            info[i-1]+=1
            info[i]-=1
        if(i+1<n+1 and info[i+1]==0 and info[i]>=2):
            info[i+1]+=1
            info[i]-=1
    for i in range(1,n+1):
        if(info[i]>=1):
            answer+=1
    return answer