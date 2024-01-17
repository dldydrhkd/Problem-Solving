def solution(players, callings):
    answer = []
    li = {}
    num = {}
    for i in range(len(players)):
        li[players[i]] = i+1
    for i in range(len(players)):
        num[i+1] = players[i]
    
    for calling in callings:
        post = calling              # 현재 선수 이름
        post_num = li[post]         # 현재 선수의 번호
        
        pre = num[post_num-1]       # 뒤쳐질 선수의 이름
        pre_num = li[pre]           # 뒤쳐질 선수의 번호
        
        li[post] = pre_num
        li[pre] = post_num
        
        num[pre_num] = post
        num[post_num] = pre
    for key,value in sorted(num.items()):
        answer.append(value)
    return answer
