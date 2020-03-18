#include <iostream>
using namespace std;

int n;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	

	cin >> n;


	while (n--) {
		int k;
		cin >> k;
		
		while (1) {
			if (k % 2 == 0) {
				k /= 2;
			}
			else {
				break;
			}
		}

		if (k == 1) {
			cout << "GoHanGang\n";
		}
		else {
			cout << "Gazua\n";
		}

	}
	
}