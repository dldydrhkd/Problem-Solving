class Solution:
    def fib(self, n: int) -> int:
        arr = [0]*31
        arr[1] = 1
        for i in range(2,n+1):
            arr[i] = arr[i-1]+arr[i-2]
        return arr[n]