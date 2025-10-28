import sys
from collections import deque

input = sys.stdin.readline

t = int(input())

while(t):
	t -= 1
	li = input()
	st = deque()
	flag = True
	for i in li:
		if i == '(':
			st.append('(')
		elif i == ')':
			if st:
				st.pop()
			else:
				print('NO')
				flag = False
				break
	if flag:
		if not st:
			print('YES')
		else:
			print('NO')