#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <cstring>
#include <stack>
using namespace std;
bool visited[100001];
vector<pair<int, int>> v[100001];
int parameter = 0;
int far = 0;

void dfs(int node, int dist) {
	visited[node] = true;
	for (int i = 0; i < v[node].size(); i++) {
		int next = v[node][i].first;
		if (!visited[next]) {
			dfs(next, v[node][i].second + dist);
			if (parameter < v[node][i].second + dist) {
				parameter = v[node][i].second + dist;
				far = next;
			}
		}
	}
}

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int a;
		cin >> a;
		while (true) {
			int b;
			cin >> b;
			if (b == -1) {
				break;
			}
			int c;
			cin >> c;
			v[a].push_back({ b,c });
		}
	}
	dfs(1, 0);
	memset(visited, false, sizeof(visited));
	dfs(far, 0);

	cout << parameter;
}