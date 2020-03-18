#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;

	int first = 1;
	int last = k;
	int mid;
	int result = 0;
	while (first <= last) {
		mid = (first + last) / 2;
		int sum = 0;
		for (int i = 1; i <= n; i++) {
			sum += min(n, mid / i);		// count number less than mid
		if (sum < k) {
			first = mid + 1;
		}
		else {
			result = mid;
			last = mid- 1;
		}
	}
	cout << result;

}
