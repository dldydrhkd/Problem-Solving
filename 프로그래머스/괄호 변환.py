def check(s):
    li = []
    for i in s:
        if(i=='('):
            li.append(i)
        else:
            if(li!=[]):
                li.pop();
            else:
                return False;
    if(li!=[]):
        return False;
    return True

def cal(s):
    if(s==""):
        return ""
    cnt1 = 0
    cnt2 = 0
    u = ""
    for i in s:
        u+=i
        if(i=='('):
            cnt1+=1
        else:
            cnt2+=1
        if(cnt1==cnt2):
            break
    v = s[len(u):]
    if(check(u)):
        return u + cal(v)
    else:
        temp = '('
        temp += cal(v)
        temp += ')'
        for j in u[1:len(u)-1]:
            if(j=='('):
                temp+=')'
            else:
                temp+='('
        return temp

def solution(p):
    answer = cal(p)
    return answer
