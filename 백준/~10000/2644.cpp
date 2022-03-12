#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int parent[101];
vector<int> v[101];
bool visited[101];
int chon[101];
int n, m;

void bfs(int node) {
	queue<int> q;
	visited[node] = true;
	q.push(node);

	while (!q.empty()) {
		int there = q.front();
		q.pop();
		for (int i = 0; i < v[there].size(); i++) {
			if (!visited[v[there][i]]) {
				q.push(v[there][i]);
				visited[v[there][i]] = true;
				chon[v[there][i]] = chon[there] + 1;
			}
			
		}
	}

}
int main() {
	cin >> n;
	int a, b;
	cin >> a >> b;
	cin >> m;

	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		parent[y] = x;
		v[x].push_back(y);
		v[y].push_back(x);
	}

	bfs(b);

	if (!visited[a]) {
		cout << "-1";
	}
	else {
		cout << chon[a];
	}
}