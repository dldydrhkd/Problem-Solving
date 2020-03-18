#include <iostream>
using namespace std;
long long arr[102][102][102];

int main() {
	int n, l, r;
	cin >> n >> l >> r;

	arr[1][1][1] = 1;
	arr[2][2][1] = 1;
	arr[2][1][2] = 1;
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= l; j++) {
			for (int k = 1; k <= r; k++) {
				arr[i + 1][j][k] = arr[i][j - 1][k] + arr[i][j][k - 1] + arr[i][j][k] * (i - 2 + 1);
				arr[i + 1][j][k] %= 1000000007;
			}
		}
	}

	cout << arr[n][l][r] << "\n";
}