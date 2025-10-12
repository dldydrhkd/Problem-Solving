import sys

input = sys.stdin.readline

m = {1:'C',2:'B',3:'A',4:'E',0:'D'}

for i in range(3):
    li = input().split()
    t_sum = 0
    for l in li:
        if(l=='1'):
            t_sum+=1
    print(m[t_sum])