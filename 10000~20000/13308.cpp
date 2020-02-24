#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
ll n, m;
ll oil[2501];
vector<pair<ll, ll>> v[2501];
bool visited[2501][2501];

struct node {
	ll city;
	ll cost;
	ll dist;
};

bool operator<(node r, node t) {
	return r.dist > t.dist;
}

ll func() {
	priority_queue<node> pq;
	pq.push({ 1,oil[1],0 });
	while (!pq.empty()) {
		node now = pq.top();
		ll idx = now.city, cost = now.cost, dist = now.dist;
		pq.pop();

		if (visited[idx][cost]) {
			continue;
		}

		if (idx == n) {
			return dist;
		}

		visited[idx][cost] = true;
		
		for (int i = 0; i < v[idx].size(); i++) {
			ll next = v[idx][i].first;
			ll next_cost = v[idx][i].second;
			pq.push({ next,min(cost,oil[next]),dist + next_cost * cost });
		}
	}
}

int main() {
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		cin >> oil[i];
	}

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
	}

	cout << func();
}
