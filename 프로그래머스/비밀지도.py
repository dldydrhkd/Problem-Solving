def solution(n, arr1, arr2):
    answer = []
    li = [[' ']*n for _ in range(n)]
    for i in range(0,len(arr1)):
        temp = arr1[i] | arr2[i]
        temp = list(bin(temp))
        temp = temp[2:]
        for j in range(len(temp)):
            if(temp[j]=='1'):
                li[i][n-len(temp)+j] = '#'
    for i in range(n):
        temp = ''.join(li[i])
        answer.append(temp)
    return answer