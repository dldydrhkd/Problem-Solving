import sys

input = sys.stdin.readline

n = int(input().strip())

li = [input().strip() for _ in range(n)]

def cal(temp):
    val = 0
    for i in temp:
        if(str(i).isdigit()):
            val+=int(i)
    return val

li.sort(key = lambda x : (len(x),cal(x),x))
for j in li:
    print(j)