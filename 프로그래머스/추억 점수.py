def solution(name, yearning, photo):
    answer = []
    score = {}
    for i in range(len(name)):
        score[name[i]] = yearning[i]
    for p in photo:
        sc = 0
        for i in p:
            if i in score:
                sc+=score[i]
        answer.append(sc)
    return answer
