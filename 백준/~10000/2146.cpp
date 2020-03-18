#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;

int n;
int arr[101][101];
int s[100001];
bool visited[101][101];
int x[] = { 0,0,-1,1 };
int y[] = { -1,1,0,0 };
int num = 1;
int ans;
bool flag = false;

bool check(int a, int b) {
	if (a >= 0 && a < n && b >= 0 && b < n) {
		return true;
	}
	return false;
}

void dfs(int a, int b) {
	visited[a][b] = true;
	arr[a][b] = num;
	for (int i = 0; i < 4; i++) {
		int nx = a + x[i];
		int ny = b + y[i];

		if (check(nx, ny) && !visited[nx][ny] && arr[nx][ny]) {
			dfs(nx, ny);
		}
	}
}

void bfs(int a, int b) {
	queue<pair<int, int>> q;
	q.push({ a,b });
	visited[a][b] = true;
	while (!q.empty()) {
		int front_x = q.front().first;
		int front_y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = front_x + x[i];
			int ny = front_y + y[i];

			if (check(nx, ny) && !visited[nx][ny] && arr[nx][ny] == arr[front_x][front_y]) {
				q.push({ nx,ny });
				visited[nx][ny] = true;
			}

			else if (check(nx, ny) && !visited[nx][ny] && arr[nx][ny] == 0) {
				arr[nx][ny] = arr[front_x][front_y];
				visited[nx][ny] = true;
			}

			else if (check(nx, ny) && arr[nx][ny] != 0 && arr[nx][ny] != arr[front_x][front_y]) {
				ans = s[arr[front_x][front_y]] + s[arr[nx][ny]];
			}
		}
	}
	s[arr[a][b]]++;
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	int cnt = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j] && arr[i][j]) {
				dfs(i, j);
				num++;
			}
		}
	}

	memset(visited, 0, sizeof(visited));

	while (1) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (!visited[i][j] && arr[i][j] != 0) {
					bfs(i, j);
					if (ans) {
						cout << ans;
						return 0;
					}
				}
			}
		}
		memset(visited, 0, sizeof(visited));
	}
	
	



	
}