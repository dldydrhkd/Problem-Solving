#include <iostream>
using namespace std;
typedef long long ll;
ll arr[1000002];
ll ans[1000002];

int main() {
	int n, m;
	ll sum = 0;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		int num;
		cin >> num;

		arr[i] = (arr[i - 1] + num) % m;

		ans[arr[i]]++;
	}

	for (int i = 0; i < m; i++) {
		sum += ans[i] * (ans[i] - 1) / 2;
	}

	cout << sum +ans[0]<< "\n";
}