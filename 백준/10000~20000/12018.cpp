#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct subject {
	int now;
	int restrict;
	vector<int> v;
	int max;
};

bool cmp(int a, int b) {
	return a > b;
}

vector<subject> t;

bool compare(subject a, subject b) {
	return a.max < b.max;
}

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		subject temp;
		cin >> temp.now >> temp.restrict;
		for (int j = 0; j < temp.now; j++) {
			int a;
			cin >> a;
			temp.v.push_back(a);
		}
		sort(temp.v.begin(), temp.v.end(),cmp);
		if (temp.restrict <= temp.now) {
			temp.max = temp.v[temp.restrict - 1];
			if (temp.max > 36) {
				temp.max = 36;
			}
		}
		else {
			temp.max = 1;
		}
		
		t.push_back(temp);
	}
	sort(t.begin(), t.end(), compare);
	int cnt = 0;

	for (int i = 0; i < t.size(); i++) {
		if (m - t[i].max < 0) {
			break;
		}
		m -= t[i].max;
		cnt++;
	}
	cout << cnt;
}