import sys

input = sys.stdin.readline

t = int(input().strip())

for i in range(t):
    s = input().strip()
    front = []
    back = []
    for j in s:
        if(j=='-'):
            if(front):
                front.pop()
        elif(j=='>'):
            if(back):
                front.append(back.pop())
        elif(j=='<'):
            if(front):
                back.append(front.pop())
        else:
            front.append(j)
    back = reversed(back)
    print(''.join(front)+''.join(back))