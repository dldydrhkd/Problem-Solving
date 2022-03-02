import heapq

uni = [i for i in range(0,101)]

def union(a, b):
    x = find(a)
    y = find(b)
    uni[x] = y

def find(a):
    if(uni[a] == a):
        return a
    else:
        return find(uni[a])

def solution(n, costs):
    answer = 0
    heap = []
    for i in range(len(costs)):
        heapq.heappush(heap,(costs[i][2],costs[i][0],costs[i][1]))
    while(heap):
        cost,a,b = heapq.heappop(heap)
        if(a>b):
            a,b = b,a
        if(find(a)!=find(b)):
            print(find(a), find(b))
            union(a,b)
            answer+=cost
    return answer
