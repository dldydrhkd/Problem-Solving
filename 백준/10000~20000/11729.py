import sys

input = sys.stdin.readline

n = int(input())

def hanoi(num, now, to):
    if num == 1:
        print(now, to)
    else:
        hanoi(num-1, now, 6-now-to)
        print(now, to)
        hanoi(num-1, 6-now-to, to)


if __name__ == "__main__":
    print(2**n-1)
    hanoi(n, 1, 3)