#include <iostream>
#include <queue>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;
int x[] = { 0,0,-1,1 };
int y[] = { 1,-1,0,0 };
int n;
int arr[101][101];
bool visited[101][101];

bool check(int a, int b) {
	if (a >= 0 && a < n && b >= 0 && b < n) {
		return true;
	}
	return false;
}

void bfs(int a, int b, int h) {
	queue<pair<int, int>> q;
	q.push({ a, b });
	visited[a][b] = true;
	while (!q.empty()) {
		int front_x = q.front().first;
		int front_y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = front_x + x[i];
			int ny = front_y + y[i];

			if (!visited[nx][ny] && arr[nx][ny] <= h && check(nx, ny)) {
				visited[nx][ny] = true;
				q.push({ nx,ny });
			}
		}
	}
}

void dfs(int a, int b) {
	visited[a][b] = true;

	for (int i = 0; i < 4; i++) {
		int nx = a + x[i];
		int ny = b + y[i];

		if (!visited[nx][ny] && check(nx, ny)) {
			dfs(nx, ny);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	int ans = 0;

	for (int i = 1; i <= 100; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				if (!visited[j][k] && arr[j][k] <= i) {
					bfs(j, k, i);
				}
			}
		}
		int cnt = 0;
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				if (!visited[j][k]) {
					dfs(j, k);
					cnt++;
				}
			}
		}
		ans = max(ans, cnt);
		memset(visited, 0, sizeof(visited));
	}

	if (ans == 0) {
		cout << "1";
	}
	else {
		cout << ans;
	}


}