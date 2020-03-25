#include <iostream>
#include <string>
#include <cstring>
using namespace std;
bool arr[1001];

int main() {
	memset(arr, true, sizeof(arr));
	int n;
	cin >> n;
	while (n--) {
		int str;
		int s, b;
		cin >> str >> s >> b;

		for (int i = 123; i < 1000; i++) {
			string st = to_string(i);
			if (st[0] == st[1] || st[1] == st[2] || st[0] == st[2]) {
				arr[i] = false;
			}
			if (st[0] - '0' == 0 || st[1] - '0' == 0 || st[2] - '0' == 0) {
				arr[i] = false;
			}
		}

		for (int i = 123; i < 1000; i++) {
			int strike = 0;
			int ball = 0;
			if (arr[i]) {
				string temp = to_string(i);
				string num = to_string(str);
				for (int j = 0; j < 3; j++) {
					for (int k = 0; k < 3; k++) {
						if (j == k && num[j] == temp[k]) {
							strike++;
						}
						if (j != k && num[j] == temp[k]) {
							ball++;
						}
					}
				}
			}
			if (s != strike || b != ball) {
				arr[i] = false;
			}
		}
	}
	int cnt = 0;
	for (int i = 123; i < 1000; i++) {
		if (arr[i]) {
			cnt++;
		}
	}
	cout << cnt;
}