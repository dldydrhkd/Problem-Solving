import sys

sys.setrecursionlimit(10 ** 6)
def cal_dist(a,b,c,d):
    return abs(a-c)+abs(b-d)

def cal_total_dist(c, h):
    total_dist = 0
    for i in range(len(h)):
        less_dist = 100
        for j in range(len(c)):
            less_dist = min(less_dist, cal_dist(h[i][0],h[i][1],c[j][0],c[j][1]))
        total_dist += less_dist
    return total_dist

ans = 10000

def sol(index, chicken, max_chicken, li, house):
    global ans
    if len(li) == max_chicken:
        ans = min(ans, cal_total_dist(li, house))
        return

    for i in range(index+1, len(chicken)):
        li.append((chicken[i][0], chicken[i][1]))
        sol(i,chicken,max_chicken, li,house)
        li.pop()


if __name__ == "__main__":
    
    input = sys.stdin.readline

    n,m = map(int, input().split())

    arr = [list(map(int, input().split())) for _ in range(n)]
    chicken = []
    house = []

    for i in range(n):
        for j in range(n):
            if arr[i][j] == 2:
                chicken.append((i,j))
            if arr[i][j] == 1:
                house.append((i,j))

    for i in range(len(chicken)):
        sol(i, chicken, m, [(chicken[i][0],chicken[i][1])], house)

    print(ans)