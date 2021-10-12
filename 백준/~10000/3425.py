import sys

input = sys.stdin.readline


while(1):
    str = []
    quit = 0
    while(1):
        s = input().strip()
        if(s=='QUIT'):
            quit = 1
            break
        if(s=='END'):
            break
        str.append(s)
    if(quit):
        break
    n = int(input())
    for _ in range(n):
        num = int(input())
        li = []
        li.append(num)
        err = False
        for s in str:
            if(s[:3]=='NUM'):
                li.append(int(s[4:]))
            elif not li:
                print('ERROR')
                err = True
                break
            elif(s[:3]=='POP'):
                li.pop()
            elif(s[:3]=='INV'):
                li[-1] = -li[-1]
            elif(s[:3]=='DUP'):
                li.append(li[-1])
            elif(len(li)==1):
                print('ERROR')
                err = True
                break
            elif(s[:3]=='SWP'):
                li[-1],li[-2]=li[-2],li[-1]
            elif(s[:3]=='ADD'):
                temp = li.pop() + li.pop()
                if(abs(temp) > 10**9):
                    print('ERROR')
                    err=True
                    break
                li.append(temp)
            elif(s[:3]=='SUB'):
                temp = -li.pop() + li.pop()
                if(abs(temp) > 10**9):
                    print('ERROR')
                    err=True
                    break
                li.append(temp)
            elif(s[:3]=='MUL'):
                temp = li.pop()*li.pop()
                if(abs(temp) > 10**9):
                    print('ERROR')
                    err = True
                    break
                li.append(temp)
            elif(s[:3]=='DIV'):
                a = li.pop()
                b = li.pop()
                if(a==0):
                    print('ERROR')
                    err = True
                    break
                temp = abs(b) // abs(a)
                if (a > 0 and b < 0) or (a < 0 and b > 0):
                    temp = -temp
                li.append(temp)
            elif(s[:3]=='MOD'):
                a = li.pop()
                b = li.pop()
                if(a==0):
                    print('ERROR')
                    err = True
                    break
                temp = abs(b) % abs(a)
                if b < 0:
                    temp = -temp
                li.append(temp)
        if(err):
            continue
        if(len(li)==1):
            print(li[0])
        else:
            print('ERROR')
    print()
    input()