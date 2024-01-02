answer = [-1,-1]

def solution(users, emoticons):
    n = len(users)
    m = len(emoticons)
    discount = [10, 20, 30, 40]
    discount_list = [0]*m
    
    
    def back_tracking(idx):
        global answer
        if(idx==m):
            total_cost = 0
            total_reg = 0
            for i in range(n):
                tmp_cost = 0
                for j in range(m):
                    if(users[i][0]<=discount_list[j]):
                        tmp_cost += emoticons[j] * (100-discount_list[j])/100
                if(tmp_cost >= users[i][1]):
                    tmp_cost = users[i][1]
                    total_reg+=1
                else:
                    total_cost+=tmp_cost
            if(answer[0] < total_reg):
                answer = [total_reg, total_cost]
            elif(answer[0] == total_reg and answer[1] < total_cost):
                answer[1] = total_cost
            return
        else:
            for i in range(4):
                discount_list[idx] = discount[i]
                back_tracking(idx+1)
    back_tracking(0)
    return answer
