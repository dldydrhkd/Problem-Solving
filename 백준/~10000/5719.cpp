#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#define INF 987654321
using namespace std;
int n, m, s, d;

vector<pair<int, int>> v[501];
vector<int> trace[501];
int visited[501][501];

vector<int> func(int start, int num) {
	vector<int> ver(num, INF);

	priority_queue<pair<int, int>> pq;
	pq.push({ 0,start });
	ver[start] = 0;

	while (!pq.empty()) {
		int now = pq.top().second;
		int now_cost = -pq.top().first;
		pq.pop();

		for (int i = 0; i < v[now].size(); i++) {
			int next = v[now][i].first;
			int next_cost = v[now][i].second + now_cost;

			if (visited[now][next] == -1) {
				continue;
			}

			if (ver[next] > next_cost) {
				ver[next] = next_cost;
				pq.push({ -next_cost,next });

				trace[next].clear();
				trace[next].push_back(now);
			}
			else if (ver[next] == next_cost) {
				trace[next].push_back(now);
			}
		}
	}
	return ver;
}

void bfs(int dest) {
	queue<int> q;
	q.push(dest);

	while (!q.empty()) {
		int front = q.front();
		q.pop();
		for (int i = 0; i < trace[front].size(); i++) {
			int next = trace[front][i];
			q.push(next);
			visited[next][front] = -1;
		}
	}
}


int main() {
	while (1) {
		cin >> n >> m;
		if (n == 0 && m == 0) {
			return 0;
		}
		cin >> s >> d;

		for (int i = 0; i < n; i++) {
			v[i].clear();
			trace[i].clear();
			for (int j = 0; j < n; j++) {
				visited[i][j] = 0;
			}
		}

		for (int i = 0; i < m; i++) {
			int a, b, c;
			cin >> a >> b >> c;
			v[a].push_back({ b,c });
		}

		func(s, n);
		bfs(d);

		vector<int> ans = func(s, n);

		if (ans[d] == INF) {
			cout << "-1\n";
		}
		else {
			cout << ans[d] << "\n";
		}
	}

}