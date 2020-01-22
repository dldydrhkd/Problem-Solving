#include <iostream>
#include <queue>
#include <vector>
using namespace std;
typedef unsigned long long ll;
int n, m, p;
int x[] = { 0,0,-1,1 };
int y[] = { 1,-1,0,0 };
char arr[1001][1001];
queue<pair<int, int>> q[1001];
ll s[10];
int ans[1001];
bool visited[1001][1001];

bool check(int a, int b) {
	if (a >= 0 && a < n && b >= 0 && b < m) {
		return true;
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m >> p;

	for (int i = 1; i <= p; i++) {
		cin >> s[i];
		if (s[i] > m*n) {
			s[i] = m * n;
		}
	}
	int cnt = m * n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] != '.' && arr[i][j] != '#') {
				int a = arr[i][j] - '0';
				ans[a]++;
				q[a].push({ i, j });
				visited[i][j] = true;
				cnt--;
			}
			if (arr[i][j] == '#') {
				visited[i][j] = true;
				cnt--;
			}
		}
	}
	int cnt2 = 0;
	while (1) {
		cnt2 = cnt;
		for (int i = 1; i <= p; i++) {
			for (int j = 0; j < s[i]; j++) {
				int size = q[i].size();
				while (size--) {
					int front_x = q[i].front().first;
					int front_y = q[i].front().second;
					q[i].pop();

					for (int k = 0; k < 4; k++) {
						int nx = front_x + x[k];
						int ny = front_y + y[k];

						if (check(nx, ny) && !visited[nx][ny]) {
							visited[nx][ny] = true;
							q[i].push({ nx,ny });
							ans[i] += 1;
							cnt--;
						}
					}

				}
			}
		}
		if (cnt2 == cnt) {
			break;
		}
	}

	for (int i = 1; i <= p; i++) {
		cout << ans[i] << " ";
	}	
}