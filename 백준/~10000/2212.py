import sys

input = sys.stdin.readline

N = int(input())
K = int(input())
if(N<=K):
    print(0)
else:
    li = list(map(int,input().split()))
    li.sort()

    s = []

    for i in range(1, len(li)):
        length = li[i]-li[i-1]
        s.append(length)

    s.sort()

    result = 0
    for i in range(0, N-K):
        result += s[i]

    print(result)