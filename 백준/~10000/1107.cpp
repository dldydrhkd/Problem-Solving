#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;
int ans;
int n, m;
vector<int> v;
bool visited[1000001];

bool check(string c) {
	for (int i = 0; i < c.size(); i++) {
		for (int j = 0; j < v.size(); j++) {
			if (c[i] == v[j]+'0') {
				return false;
			}
		}
	}
	return true;
}

void bfs(int num, int cnt) {
	queue<pair<int, int>> q;
	q.push({ num,0 });
	visited[num] = true;
	while (!q.empty()) {
		int size = q.size();
		while (size--) {
			pair<int, int> here = q.front();
			q.pop();
			visited[here.first] = true;
			stringstream ss;
			ss << here.first;
			string str = ss.str();
			if (here.second > ans) {
				return;
			}
			if (check(str)) {
				int a = str.size();
				ans = min(ans, a + here.second);
			}
			if (here.first == 0) {
				if (!visited[here.first + 1]) {
					q.push({ here.first + 1,here.second + 1 });
				}
			}
			else {
				if (!visited[here.first + 1]) {
					q.push({ here.first + 1,here.second + 1 });
				}
				if (!visited[here.first - 1]) {
					q.push({ here.first - 1,here.second + 1 });
				}
			}
		}

	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a;
		cin >> a;
		v.push_back(a);
	}
	

	ans=abs(n - 100);
	bfs(n, 0);
	

	cout << ans;

}