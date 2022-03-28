from collections import deque

def solution(begin, target, words):
    answer = 0
    li = deque()
    visited = [False]*len(words)
    li.append(begin)
    while(li):
        length = len(li)
        while(length):
            length-=1
            top = li.popleft()
            if(top==target):
                return answer
            for i, val in enumerate(words):
                if not visited[i]:
                    cnt = 0
                    for j in range(len(top)):
                        if(top[j]!=val[j]):
                            cnt+=1
                    if(cnt==1):
                        li.append(val)
                        visited[i] = True
        answer+=1
    answer = 0
    return answer
