import math

def solution(progresses, speeds):
    answer = []
    i = 0
    total = 0
    while(i<len(progresses)):
        t = math.ceil((100-progresses[i])/speeds[i])
        if(t>total):
            total = t
        cnt = 0
        for j in range(i,len(progresses)):
            if(progresses[j]+speeds[j]*t >= 100):
                cnt+=1
            else:
                break
        answer.append(cnt)
        i+=cnt
    return answer
