def solution(tickets):
    answer = []
    tickets.sort(key = lambda x : (x[0],x[1]))
    visited = [False]*len(tickets)
    print(visited)
    start = "ICN"
    answer.append(start)
    def dfs(s, ticket, cnt):
        if(len(tickets)==cnt):
            return True
        for i in range(len(ticket)):
            if(s==ticket[i][0] and not visited[i]):
                answer.append(ticket[i][1])
                visited[i] = True
                temp = dfs(ticket[i][1],ticket,cnt+1)
                if(temp):
                    return True
                visited[i] = False
                answer.pop(len(answer)-1)
        return False
    dfs(start,tickets,0)
    return answer