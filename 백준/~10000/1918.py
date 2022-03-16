from re import A
import sys

input = sys.stdin.readline


s = input().strip()+')'

answer = []
opt = ['(']

for i in s:
    if (i=='+') | (i=='-'):
        while(opt[-1] in '*/+-'):
            answer.append(opt.pop())
        opt.append(i)
    elif (i=='*') | (i=='/'):
        if (opt[-1] in '*/'):
            answer.append(opt.pop())
        opt.append(i)
    elif (i=='('):
        opt.append('(')
    elif (i==')'):
        while(opt[-1]!='('):
            answer.append(opt.pop())
        opt.pop()
    else:
        answer.append(i)
print(''.join(answer))