#include <iostream>
using namespace std;
typedef long long ll;

ll arr[1025][1025];
int n, m;

ll func(int a, int b, int c, int d) {
	ll sum = 0;
	for (int i = a; i <= c; i++) {
		sum += arr[i][d] - arr[i][b - 1];
	}

	return sum;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			arr[i][j] += arr[i][j - 1];
		}
	}

	while (m--) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		cout << func(a, b, c, d) << "\n";

	}
}