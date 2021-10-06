import sys

input = sys.stdin.readline

n = int(input())

arr = [0]*(n+1)

prime = [0]

arr[1]=True
i = 2
while(i<=n):
    if(arr[i]==False):
        j=2
        while(i*j<=n):
            arr[i*j]=True
            j+=1
    i+=1

for i in range(2,n+1):
    if(not arr[i]):
        prime.append(i)

for i in range(1,len(prime)):
    prime[i]+=prime[i-1]

start = 1
end = 1

cnt = 0
while(start<=end and end<len(prime)):
    if(prime[end]-prime[start-1] == n):
        cnt+=1
        start+=1
    elif(prime[end]-prime[start-1]<n):
        end+=1
    elif(prime[end]-prime[start-1]>n):
        start+=1
print(cnt)