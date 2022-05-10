import sys

input = sys.stdin.readline

def solution(a,x):
    a.sort(key=lambda y:-y)
    li = []
    for i in range(len(a)):
        if i == 0:
            li.append(a[i])
        else:
            li.append(li[i-1]+a[i])
    for f in x:
        start = 0
        end = len(li)-1
        ans = -1
        while(start<=end):
            mid = (start+end)//2
            if li[mid]==f:
                ans = mid+1
                break
            elif li[mid]>f:
                ans = mid+1
                end = mid-1
            elif li[mid]<f:
                start = mid+1
        print(ans)

if __name__ == '__main__':
    t = int(input().strip())
    for i in range(t):
        n,q = map(int,input().strip().split())
        a = list(map(int,input().strip().split()))
        x = [int(input().strip()) for _ in range(q)]
        solution(a,x)