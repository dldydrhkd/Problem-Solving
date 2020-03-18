#include<iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define INF 987654321
using namespace std;
int n, e, p, q;
vector<pair<int, int>> v[801];

int func(int start, int dest, int num) {

	vector<int> ver(num+1, INF);

	priority_queue<pair<int, int>> pq;
	pq.push({ 0,start });
	ver[start] = 0;

	while (!pq.empty()) {
		int now = pq.top().second;
		int now_cost = -pq.top().first;
		pq.pop();
		if (now == dest) {
			break;
		}

		for (int i = 0; i < v[now].size(); i++) {
			int next = v[now][i].first;
			int next_cost = v[now][i].second + now_cost;

			if (ver[next] > next_cost) {
				ver[next] = next_cost;
				pq.push({ -next_cost,next });
			}
		}
	}

	return ver[dest];
}


int main() {
	cin >> n >> e;
	for (int i = 0; i < e; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
	}
	cin >> p >> q;

	int one_to_p, one_to_q, p_to_q, p_to_dest, q_to_dest;
	one_to_p = func(1, p, n);
	one_to_q = func(1, q, n);
	p_to_q = func(p, q, n);
	p_to_dest = func(p, n, n);
	q_to_dest = func(q, n, n);

	int ans = min(one_to_p + p_to_q + q_to_dest, one_to_q + p_to_q + p_to_dest);

	if (ans >= INF || ans < 0) {
		cout << "-1\n";
	}
	else {
		cout << ans << "\n";
	}


}