def split_terms(terms):
    dic = {}
    for term in terms:
        alpha, day = term.split(' ')
        dic[alpha] = int(day)
    return dic

def solution(today, terms, privacies):
    answer = []
    t_year, t_month, t_day = map(int, today.split('.'))
    t = split_terms(terms)
    
    for i, privacy in enumerate(privacies, start=1):
        date, alpha = privacy.split(' ')
        year, month, day = map(int, date.split('.'))
        month+=t[alpha]
        
        while(month > 12) :
            month = month-12
            year = year+1
        if t_year > year:
            answer.append(i)
        elif t_year == year:
            if t_month > month:
                answer.append(i)
            elif t_month == month:
                if t_day >= day:
                    answer.append(i)
        
    return answer
