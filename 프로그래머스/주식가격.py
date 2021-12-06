def solution(prices):
    answer = [0] * len(prices)
    st = []
    for i in range(len(prices)):
        if(st==[]):
            st.append((i,prices[i]))
        else:
            while(st != [] and st[len(st)-1][1] > prices[i]):
                temp = st[len(st)-1]
                answer[temp[0]] = i-temp[0]
                st.pop();
            st.append((i,prices[i]))
    if(st!=[]):
        while(st != []):
            temp = st[len(st)-1]
            answer[temp[0]] = len(prices)-1-temp[0]
            st.pop()
    return answer
