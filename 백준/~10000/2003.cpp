#include <iostream>
using namespace std;
int arr[10001];
int sum[10001];
int n, m;
int cnt;



int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	for (int i = 1; i <= n; i++) {
		sum[i] = sum[i - 1] + arr[i];
	}

	for (int i = 0; i <= n; i++) {
		for (int j = i+1; j <= n; j++) {
			if ((sum[j] - sum[i]) == m) {
				cnt++;
			}
		}
	}

	cout << cnt;



}