#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arr[1000001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	int key;
	cin >> key;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + n);

	

	int start = 0;
	int end = n - 1;
	int cnt = 0;

	while (start < end) {
		if (arr[start] + arr[end] == key) {
			cnt++;
			start++;
		}
		if (arr[start] + arr[end] > key) {
			end--;
		}
		if (arr[start] + arr[end] < key) {
			start++;
		}
	}

	cout << cnt;
}