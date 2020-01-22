#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int n, k, m;
vector<int> v[110001];
bool visited[110001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> k >> m;

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < k; j++) {
			int a;
			cin >> a;
			v[i + 100001].push_back(a);
			v[a].push_back(i + 100001);
		}
	}
	queue<int> q;
	q.push(1);
	visited[1] = true;
	int ans = 0;

	while (!q.empty()) {
		int size = q.size();
		ans++;
		while (size--) {
			int front = q.front();
			q.pop();
			if (front == n) {
				cout << ans / 2 + 1;
				return 0;
			}
			for (int i = 0; i < v[front].size(); i++) {
				if (!visited[v[front][i]]) {
					q.push(v[front][i]);
					visited[v[front][i]] = true;
				}
			}

		}
	}
	cout << "-1";
}