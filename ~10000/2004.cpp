#include <iostream>
#include <algorithm>
using namespace std;
typedef unsigned long long ll;

ll n, m;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	ll cnt5 = 0;
	ll cnt2 = 0;
	ll cnt = 0;

	for (ll i = 5; i <= n - m; i*=5) {
		cnt5 -= (n-m) / i;

	}
	for (ll i = 2; i <= n - m; i *= 2) {
		cnt2 -= (n - m) / i;
	}

	for (ll i = 5; i <= n; i *= 5) {
		cnt5 += n / i;
	}
	for (ll i = 2; i <= n; i *= 2) {
		cnt2 += n / i;
	}


	for (ll i = 5; i <= m; i *= 5) {
		cnt5 -= m / i;
	}
	for (ll i = 2; i <= m; i *= 2) {
		cnt2 -= m / i;
	}

	cnt = min(cnt2, cnt5);

	cout << cnt;
}
