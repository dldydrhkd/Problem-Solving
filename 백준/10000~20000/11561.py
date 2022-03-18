import sys

input = sys.stdin.readline

t = int(input().strip())

def check(jump,n):
    if jump*(jump+1)<=2*n:
        return True
    return False

while(t):
    n = int(input().strip())
    start = 1
    end = n
    answer = 0
    while(start<=end):
        mid = (start+end)//2
        if(check(mid,n)):
            answer = max(answer, mid)
            start = mid+1
        else:
            end = mid-1
    t-=1
    print(answer)