def solution(table, languages, preference):
    answer = ''
    sum = 0
    name = 'SI'
    for str in table:
        li = str.split(' ')
        temp_sum = 0
        for i in range(len(languages)):
            for j in range(1, len(li)):
                if(languages[i]==li[j]):
                    temp_sum = temp_sum+(preference[i]*(6-j))
        if(temp_sum>sum):
            sum = temp_sum
            name = li[0]
        elif(temp_sum==sum):
            if(name>li[0]):
                name = li[0]
    answer = name
    return answer