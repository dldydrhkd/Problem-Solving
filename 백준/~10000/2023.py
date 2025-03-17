import sys
import math

input = sys.stdin.readline
sys.setrecursionlimit(10000)

n = int(input())

def is_prime(num):
    for i in range(2, int(math.sqrt(num))+1):
        if num%i==0:
            return False
    return True

def sol():
    def dfs(num):
        if len(str(num)) == n:
            print(num)
        for i in range(1,10,2):
            if len(str(num*10+i)) <= n and is_prime(num*10+i):
                dfs(num*10+i)
    dfs(2)
    dfs(3)
    dfs(5)
    dfs(7)


if __name__ == "__main__":
    sol()