#include <iostream>
#include <algorithm>
using namespace std;

#define INF 987654321

int g[101][101];
int n, m;

void floyd() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				if (g[k][j] > g[k][i] + g[i][j]) {
					g[k][j] = g[k][i] + g[i][j];
				}
			}
		}
	}
}


int main() {
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) {
				g[i][j] = 0;
			}
			else {
				g[i][j] = INF;
			}
		}
	}

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		g[a][b] = min(c, g[a][b]);
	}

	floyd();

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (g[i][j] == INF) {
				cout << "0 ";
			}
			else {
				cout << g[i][j] << " ";
			}
		}
		cout << "\n";
	}
}