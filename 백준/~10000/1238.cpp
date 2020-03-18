#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define INF 987654321

vector<pair<int, int>> v[1001];
int arr[1001];


int main() {
	int n, m, x;
	cin >> n >> m >> x;
	vector<int> back(n + 1, INF);
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
	}


	for (int i = 1; i <= n; i++) {
		priority_queue<pair<int, int>> pq;
		vector<int> go(n + 1, INF);
		pq.push({ 0,i });
		go[i] = 0;
		int cost = 0;
		while (!pq.empty()) {
			int now = pq.top().second;
			int now_val = -pq.top().first;
			pq.pop();
			if (now == x) {
				cost = now_val;
				break;
			}
			
			for (int j = 0; j < v[now].size(); j++) {
				int next = v[now][j].first;
				int next_val = v[now][j].second;
				if (go[next] > next_val + now_val) {
					go[next] = next_val + now_val;
					pq.push({ -(next_val + now_val),next });
				}
			}
		}
		arr[i] = cost;
	}

	priority_queue<pair<int, int>> pq;
	pq.push({ 0,x });
	back[x] = 0;
	while (!pq.empty()) {
		int now = pq.top().second;
		int now_val = -pq.top().first;
		pq.pop();
		for (int j = 0; j < v[now].size(); j++) {
			int next = v[now][j].first;
			int next_val = v[now][j].second;
			if (back[next] > next_val + now_val) {
				back[next] = next_val + now_val;
				pq.push({ -(next_val + now_val),next });
			}
		}
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		ans = max(ans, arr[i] + back[i]);
	}

	cout << ans;
}