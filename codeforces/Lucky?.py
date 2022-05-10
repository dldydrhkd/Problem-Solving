import sys

input = sys.stdin.readline

def solution(li):
    for i in li:
        front = 0
        back = 0
        for j in range(0,3):
            front += int(i[j])
        for j in range(3,6):
            back += int(i[j])
        if front == back:
            print('YES')
        else:
            print('NO')

if __name__ == '__main__':
    n = int(input().strip())
    li = [str(input().strip()) for _ in range(n)]
    solution(li)