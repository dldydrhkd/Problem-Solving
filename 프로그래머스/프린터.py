def solution(priorities, location):
    answer = 0
    li = []
    cnt =0
    for i in range(len(priorities)):
        li.append((i,priorities[i]))
    while(li):
        idx,pri = li.pop(0)
        check = False
        for i,p in li:
            if(pri<p):
                check=True
                break
        if(check):
            li.append((idx,pri))
        else:
            if(location==idx):
                answer=cnt+1
                break
            else:
                cnt+=1
    return answer