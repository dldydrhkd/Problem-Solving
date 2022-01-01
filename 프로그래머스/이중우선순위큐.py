import heapq

def solution(operations):
    answer = []
    
    maxq = []
    minq = []
    
    for s in operations:
        a,b = s.split()
        b = int(b)
        if(a=='I'):
            heapq.heappush(maxq,-b)
            heapq.heappush(minq,b)
        elif(a=='D'):
            if(b==1 and maxq):
                heapq.heappop(maxq)
                while(maxq and -maxq[0]<minq[0]):
                    heapq.heappop(maxq)
                if(not maxq):
                    minq=[]
            elif(b==-1 and minq):
                heapq.heappop(minq)
                while(minq and -maxq[0]<minq[0]):
                    heapq.heappop(minq)
                if(not minq):
                    maxq=[]
    if(minq):
        answer.append(-maxq[0])
        answer.append(minq[0])
    else:
        answer.append(0)
        answer.append(0)
    return answer