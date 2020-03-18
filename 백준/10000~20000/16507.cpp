#include <iostream>
using namespace std;
int arr[1001][1001];

int func(int a, int b, int c, int d) {
	int sum = 0;
	for (int i = a; i <= c; i++) {
		sum += arr[i][d] - arr[i][b - 1];
	}
	return sum / ((c - a + 1)*(d - b + 1));
}

int main() {
	int r, c, q;
	cin >> r >> c >> q;
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			cin >> arr[i][j];
			arr[i][j] += arr[i][j - 1];
		}
	}


	while (q--) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		cout<<func(a, b, c, d)<<"\n";
	}
}