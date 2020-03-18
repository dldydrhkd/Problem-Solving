#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define INF 987654321
int v, m, j, s;
int arr[101][101];

void floyd() {
	for (int via = 1; via <= v; via++) {
		for (int from = 1; from <= v; from++) {
			for (int to = 1; to <= v; to++) {
				if (from == to) {
					continue;
				}
				else if (arr[from][via] && arr[via][to]) {
					if (arr[from][to] == 0) {
						arr[from][to] = arr[from][via] + arr[via][to];
					}
					else if (arr[from][to] > arr[from][via] + arr[via][to]) {
						arr[from][to] = arr[from][via] + arr[via][to];
					}
				}
			}
		}
	}
}

int main() {
	cin >> v >> m;

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		if (!arr[a][b]) {
			arr[a][b] = c;
			arr[b][a] = c;
		}
		else {
			arr[a][b] = min(arr[a][b], c);
			arr[b][a] = arr[a][b];
		}
	}

	cin >> j >> s;


	floyd();

	int ans = -1;
	
	if (arr[j][s] == 0) {
		cout << ans;
		return 0;
	}

	int mnd = INF, dist = INF;
	for (int via = 1; via <= v; via++) {
		if (via == s || via == j) continue;
		if (arr[s][via] == 0 || arr[via][j] == 0) continue;
		mnd = min(mnd, arr[s][via] + arr[via][j]);
	}

	for (int via = 1; via <= v; via++) {
		if (via == j || via == s) continue;
		if (arr[s][via] == 0 || arr[via][j] == 0) continue;
		if (mnd != arr[s][via] + arr[via][j]) continue;
		if (arr[j][via] > arr[via][s]) continue;
		if (dist > arr[j][via]) {
			ans = via;
			dist = arr[j][via];
		}
	}

	cout << ans;
	return 0;
}
