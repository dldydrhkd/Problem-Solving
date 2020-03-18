#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;
int x[] = { 0,0,-1,1 };
int y[] = { 1,-1,0,0 };
bool arr[51][51];
bool visited[51][51];
int m, n;
int ans;

bool check(int a, int b) {
	if (a >= 0 && a < m && b >= 0 && b < n) {
		return true;
	}
	return false;
}

void bfs(int a, int b, int c) {
	queue<pair<pair<int, int>,int>> q;
	q.push({ { a,b },c });
	visited[a][b] = true;
	while (!q.empty()) {
		int size = q.size();
		while (size--) {
			int front_x = q.front().first.first;
			int front_y = q.front().first.second;
			int val = q.front().second;
			q.pop();

			for (int i = 0; i < 4; i++) {
				int nx = front_x + x[i];
				int ny = front_y + y[i];

				if (check(nx, ny) && !visited[nx][ny] && !arr[nx][ny]) {
					q.push({ {nx,ny},val + 1 });
					visited[nx][ny] = true;
					ans = max(ans, val + 1);
				}
			}
		}
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> m >> n;
	
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			char a;
			cin >> a;
			if (a == 'W') {
				arr[i][j] = true;
			}
			if (a == 'L') {
				arr[i][j] = false;
			}
		}
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == false) {
				bfs(i, j, 0);
				memset(visited, 0, sizeof(visited));
			}
			
		}
	}

	cout << ans;

}