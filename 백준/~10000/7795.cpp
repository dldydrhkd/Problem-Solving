#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int arr[20001] = { 0, };
		int brr[20001] = { 0, };

		int n, m;
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		for (int i = 0; i < m; i++) {
			cin >> brr[i];
		}

		sort(arr, arr + n);
		sort(brr, brr + m);

		int a = 0;
		int b = 0;
		int cnt = 0;
		int temp = 0;
		while (a < n && b < m) {
			if (arr[a] <= brr[b]) {
				a++;
				cnt += temp;
			}
			if (arr[a] > brr[b]) {
				b++;
				cnt++;
				temp++;
			}
		}

		cnt += (n-1-a)*temp;
		cout << cnt << "\n";
	}
}