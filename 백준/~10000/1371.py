import sys

li = [0]*26

lines = sys.stdin.readlines()

for line in lines:
    for l in line:
        if l.isalpha():
            li[ord(l)-ord('a')]+=1

max_num = max(li)
answer = []
for i in range(len(li)):
    if li[i] == max_num:
        answer.append(chr(ord('a')+i))

print(''.join(answer))