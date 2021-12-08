from itertools import combinations

def solution(numbers, target):
    answer = 0
    total = sum(numbers)
    for i in range(0,len(numbers)+1):
        li = list(combinations(numbers,i))
        for j in li:
            temp = total - 2*sum(j)
            if(temp==target):
                answer+=1
    return answer