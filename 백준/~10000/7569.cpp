#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;
int m, n, h;
int arr[101][101][101];
int x[] = {0,0,-1,1,0,0};
int y[] = {1,-1,0,0,0,0};
int z[] = {0,0,0,0,-1,1};
bool visited[101][101][101];

bool check(int a, int b, int c) {
	if (a >= 0 && a < n && b >= 0 && b < m && c >= 0 && c < h) {
		return true;
	}
	return false;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> m >> n >> h;
	int cnt = m * n*h;
	vector<pair<pair<int, int>, int>> v;

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				cin >> arr[i][j][k];
				if (arr[i][j][k] == 1) {
					cnt--;
					v.push_back({{ j,k }, i});
				}
				if (arr[i][j][k] == -1) {
					cnt--;
				}
			}
		}
	}
	int day = -1;
	queue < pair<pair<int, int>, int>> q;
	for (int i = 0; i < v.size(); i++) {
		q.push({{ v[i].first.first,v[i].first.second }, v[i].second });
		visited[v[i].second][v[i].first.first][v[i].first.second] = true;
	}


	if (cnt == 0) {
		cout << "0";
	}
	else {
		while (!q.empty()) {
			int size = q.size();
			day++;
			while (size--) {
				int a = q.front().first.first;
				int b = q.front().first.second;
				int c = q.front().second;
				q.pop();

				for (int j = 0; j < 6; j++) {
					int nx = a + x[j];
					int ny = b + y[j];
					int nz = c + z[j];
					if (!visited[nz][nx][ny] && check(nx, ny, nz)) {
						if (arr[nz][nx][ny] == -1) {
							visited[nz][nx][ny] = true;
							continue;
						}
						else {
							visited[nz][nx][ny] = true;
							cnt--;
							q.push({ {nx, ny}, nz });
						}
					}
				}
			}
		}

		if (cnt == 0) {
			cout << day;
		}
		else {
			cout << "-1";
		}
	}
}