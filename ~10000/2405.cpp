#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
ll n;
vector<ll> v;
ll ans;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (ll i = 0; i < n; i++) {
		ll a;
		cin >> a;
		v.push_back(a);
	}

	sort(v.begin(), v.end());

	//after sorting, can make the case into two part
	//a+b+c/3 - b or b- a+b+c/3 
	// after all you will multiply 3, so
	//we need to find max value of a-2b+c, -a+2b-c
	// for a-2b+c to be max we fix c by max and make b the least number while a is moving
	// for -a+2b-c to be max we fix a by min and make b the max number while c is moving

	for (ll i = 0; i < n-2; i++) {
		ans = max(ans, abs(v[n - 1] + v[i] - v[i + 1] * 2));
	}
	for (ll i = 1; i < n-1; i++) {
		ans = max(ans, abs(-v[0] + v[i] * 2 - v[i + 1]));
	}
	cout << ans;
}