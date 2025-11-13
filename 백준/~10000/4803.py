import sys
from collections import deque

input = sys.stdin.readline

def bfs(n, graph, visited):
	cnt = 0
	for i in range(1, n+1):
		if not visited[i]:
			dq = deque()
			dq.append(i)
			visited[i] = True
			edge_count = 0
			node_count = 1
			while(dq):
				top = dq.popleft()
				edge_count += len(graph[top])
				for child in graph[top]:
					if not visited[child]:
						dq.append(child)
						node_count+=1
						visited[child] = True
			if node_count-1 == edge_count//2:
				cnt+=1
	return cnt

t = 0

while(True):
	t+=1
	n, m = map(int,input().split())
	if n==0 and m==0:
		break
	graph = [[] for _ in range(n+1)]
	visited = [False]*(n+1)
	for _ in range(m):
		a, b = map(int, input().split())
		graph[a].append(b)
		graph[b].append(a)
	cnt = bfs(n, graph, visited)
	if cnt == 0:
		print(f'Case {t}: No trees.')
	elif cnt == 1:
		print(f'Case {t}: There is one tree.')
	else:
		print(f'Case {t}: A forest of {cnt} trees.')