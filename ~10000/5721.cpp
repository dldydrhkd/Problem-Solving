#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	while (1) {
		int n, m;
		cin >> n >> m;
		if (n==0 && m==0) {
			return 0;
		}
		int arr[100001] = { 0, };
		int dp[100001] = { 0, };
		int res[100001] = { 0, };
		int ans[100001] = { 0, };

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				cin >> arr[j];
			}

			for (int j = 1; j <= m; j++) {
				if (j == 1) {
					dp[j] = arr[j];
					continue;
				}
				dp[j] = max(dp[j - 1], arr[j] + dp[j - 2]);
			}
			res[i] = dp[m];
		}		
		
		for (int i = 1; i <= n; i++) {
			if (i == 1) {
				ans[i] = res[i];
				continue;
			}
			ans[i] = max(ans[i-1], res[i] + ans[i-2]);
		}
		cout << ans[n]<<"\n";
		
	}

}