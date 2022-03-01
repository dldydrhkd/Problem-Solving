def solution(name):
    answer = 0
    for i in range(len(name)):
        if(name[i]!='A'):
            answer += min(ord(name[i])-ord('A'),26-ord(name[i])+ord('A'))
    first_alpha = 0
    for i in range(1, len(name)):
        if(name[i]!='A' and first_alpha == 0):
            first_alpha = i
            break
    last_alpha = 0
    for i in range(1, len(name)):
        if(name[i]!='A'):
            last_alpha = i
    move = min(len(name)-first_alpha, last_alpha)
    for i in range(1, len(name)):
        if(name[i]!='A'):
            for j in range(i+1, len(name)):
                if(name[j]!='A'):
                    move = min(move,2*i+len(name)-j,2*(len(name)-j)+i)
                    break
    answer+=move
    return answer
