import sys
import math

input = sys.stdin.readline

while(True):
    s = list(input().strip())
    if(s[0]=='0'):
        quit()
    s = s[::-1]
    total = 0
    for i in range(0,len(s)):
        total += int(s[i])*math.factorial(i+1)
    print(total)