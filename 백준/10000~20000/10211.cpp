#include <iostream>
#include <algorithm>
using namespace std;
int arr[1001];

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;
		
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}

		int ans = arr[0];
		int sum = 0;

		for (int i = 0; i < n; i++) {
			sum += arr[i];
			ans = max(ans, sum);
			if (sum < 0) {
				sum = 0;
			}
		}
		cout << ans << "\n";
	}
}