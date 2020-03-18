#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
#define INF 987654321
vector<pair<int, int>> v[1001];
int visited[1001];

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		visited[i] = INF;
	}

	for (int i = 0; i < m; i++) {
		int start, end, val;
		cin >> start >> end >> val;
		v[start].push_back({ end,val });
	}
	int start, end;
	cin >> start >> end;
	priority_queue<pair<int, int>> pq;
	pq.push({ 0,start });
	visited[start] = 0;
	while (!pq.empty()) {
		int now = pq.top().second;
		int now_val = -pq.top().first;
		pq.pop();
		if (now == end) {
			cout << now_val << "\n";
			return 0;
		}

		for (int i = 0; i < v[now].size(); i++) {
			int next = v[now][i].first;
			int next_val = v[now][i].second;
			if (visited[next] > next_val + now_val) {
				visited[next] = next_val + now_val;
				pq.push({ -(next_val + now_val),next });
			}
		}
	}
}