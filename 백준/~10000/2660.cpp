#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n;
int arr[51][51];
vector<int> v;
int ans = 987654321;

void floyd() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				if (j == k) {
					continue;
				}
				else if (arr[j][i] && arr[i][k]) {
					if (arr[j][k] == 0) {
						arr[j][k] = arr[j][i] + arr[i][k];
					}
					else {
						arr[j][k] = min(arr[j][k], arr[j][i] + arr[i][k]);
					}
				}
			}
		}
	}
}

int main() {
	cin >> n;
	while (1) {
		int a, b;
		cin >> a >> b;
		if (a == -1 && b == -1) {
			break;
		}
		arr[a][b] = 1;
		arr[b][a] = 1;
	}

	floyd();
	
	for (int i = 1; i <= n; i++) {
		int high = 0;
		bool check = true;
		for (int j = 1; j <= n; j++) {
			if (i == j) {
				continue;
			}
			high = max(high, arr[i][j]);

			if (arr[i][j] == 0) {
				check = false;
				break;
			}
		}
		if (check) {
			if (ans > high) {
				ans = high;
				v.clear();
				v.push_back(i);
			}
			else if (ans == high) {
				v.push_back(i);
			}
		}
	}

	cout << ans << " " << v.size() << "\n";

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
}