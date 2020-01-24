#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n;
bool arr[10001];
vector<int> prime;
pair<int, int> v[20000];

void pri() {
	for (int i = 2; i <= 100; i++) {
		int j = 2;
		while (i*j <= 10000) {
			arr[i*j] = true;
			j++;
		}
	}

	for (int i = 2; i <= 10000; i++) {
		if (arr[i] == false) {
			prime.push_back(i);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	pri();

	for (int i = 0; i < prime.size(); i++) {
		for (int j = i; j < prime.size(); j++) {
			if (v[prime[i] + prime[j]].first != 0) {
				if (v[prime[i] + prime[j]].second - v[prime[i] + prime[j]].first > prime[j] - prime[i]) {
					v[prime[i] + prime[j]] = { prime[i],prime[j] };
				}
				
			}
			else {
				v[prime[i] + prime[j]] = { prime[i],prime[j] };
			}
		}
	}

	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		cout << v[a].first << " " << v[a].second;
		cout << "\n";
	}

}