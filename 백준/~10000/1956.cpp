#include <iostream>
#include <queue>
#include <vector>
#define INF 987654321
using namespace std;
int v, e;
int arr[401][401];

void floyd() {
	for (int k = 1; k <= v; k++) {
		for (int i = 1; i <= v; i++) {
			for (int j = 1; j <= v; j++) {
				if (arr[i][k] && arr[k][j]) {
					if (arr[i][j] == 0) {
						arr[i][j] = arr[i][k] + arr[k][j];
					}
					else if (arr[i][j] > arr[i][k] + arr[k][j]) {
						arr[i][j] = arr[i][k] + arr[k][j];
					}
				}
			}
		}
	}
}


int main() {
	cin >> v >> e;
	
	for (int i = 0; i < e; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		arr[a][b] = c;
	}

	floyd();

	int ans = INF;
	for (int i = 1; i <= v; i++) {
		if (arr[i][i] != 0) {
			ans = min(ans, arr[i][i]);
		}
	}

	if (ans == INF) {
		cout << "-1";
	}
	else {
		cout << ans;
	}
}