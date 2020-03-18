#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
using namespace std;

string arr[15];
int l, c;

void func(string str,  int num) {
	if (num > c) {
		return;
	}
	if (str.size() == l) {
		bool flag = false;
		for (int i = 0; i < str.size(); i++) {
			if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u') {
				flag = true;
				break;
			}
		}
		int cnt = 0;
		for (int i = 0; i < str.size(); i++) {
			if (cnt == 2) {
				break;
			}
			if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u') {
				continue;
			}
			else {
				cnt++;
			}
		}
		if (flag && cnt == 2) {
			cout << str << "\n";
		}
		return;
	}
	string st = str + arr[num];

	func(st, num + 1);
	func(str, num+1);
	
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> l >> c;

	for (int i = 0; i < c; i++) {
		cin >> arr[i];
	}

	sort(arr, arr+c);

	func("", 0);

	

}