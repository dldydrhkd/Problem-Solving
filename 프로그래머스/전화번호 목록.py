def solution(phone_book):
    answer = True
    phone_book.sort()
    for i in range(1,len(phone_book)):
        if(phone_book[i-1] == phone_book[i][:len(phone_book[i-1])]):
            answer = False
    return answer
