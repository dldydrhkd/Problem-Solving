#include <iostream>
#include <algorithm>
using namespace std;

int n;
int a[51];
int b[51];

bool desc(int a, int b) {
	return a > b;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}
	
	sort(a, a + n);
	sort(b, b + n, desc);
	int sum = 0;

	for (int i = 0; i < n; i++) {
		sum += a[i] * b[i];
	}

	cout << sum;
}