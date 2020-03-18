#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
char arr[101][101];
int x[] = { 0,0,-1,1 };
int y[] = { 1,-1,0,0 };
bool visited[101][101];
int n, m;

bool check(int a, int b) {
	if (a >= 1 && a <= n && b >= 1 && b <= m) {
		return true;
	}
	return false;
}

int main() {
	cin >> m >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> arr[i][j];
		}
	}

	priority_queue<pair<int,pair<int,int>>> pq;
	pq.push({ 0,{1,1} });
	visited[1][1] = true;

	while (!pq.empty()) {
		int now_y = pq.top().second.first;
		int now_x = pq.top().second.second;
		int wall = -pq.top().first;
		pq.pop();

		if (now_y == n && now_x == m) {
			cout << wall << "\n";
			return 0;
		}

		for (int i = 0; i < 4; i++) {
			int nx = now_x + x[i];
			int ny = now_y + y[i];

			if (check(ny,nx) && !visited[ny][nx]) {
				if (arr[ny][nx] == '1') {
					pq.push({ -(wall + 1),{ny,nx} });
				}
				else {
					pq.push({ -wall,{ny,nx} });
				}
				visited[ny][nx] = true;
			}
		}
	}
}