def solution(friends, gifts):
    answer = 0
    friendsNum = {}
    for i in range(len(friends)):
        friendsNum[friends[i]] = i
    score = [0 for i in range(len(friends))]
    ans = [0 for i in range(len(friends))]
    arr = [[0 for i in range(len(friends))] for i in range(len(friends))]
    for gift in gifts:
        li = gift.split(" ")
        from_ = li[0]
        to_ = li[1]
        arr[friendsNum[from_]][friendsNum[to_]] += 1
        score[friendsNum[from_]]+=1
        score[friendsNum[to_]]-=1
    for friend in friends:
        for i in range(len(friends)):
            from_ = friendsNum[friend]
            to_ = i
            if friends[i] == friend :
                continue
            fromNum = arr[from_][to_]
            toNum = arr[to_][from_]
            fromScore = score[from_]
            toScore = score[to_]
            if fromNum or toNum:
                if fromNum > toNum:
                    ans[from_] += 1
                elif fromNum == toNum:
                    if fromScore > toScore:
                        ans[from_] += 1
            else:
                if fromScore > toScore:
                    ans[from_] += 1
    return max(ans)