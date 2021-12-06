def solution(bridge_length, weight, truck_weights):
    answer = 0
    st = [0]*bridge_length
    i = 0
    cur_weight = 0
    while(i<len(truck_weights)):
        if(len(st)==bridge_length):
            cur_weight -= st[0]
            st.pop(0)
        if(i<len(truck_weights)):
            if(cur_weight+truck_weights[i]<=weight and len(st)+1<=bridge_length):
                st.append(truck_weights[i])
                cur_weight += truck_weights[i]
                answer += 1
                i += 1
            else:
                st.append(0)
                answer+=1
        else:
            st.append(0)
            answer+=1
    answer+=bridge_length;
    return answer
