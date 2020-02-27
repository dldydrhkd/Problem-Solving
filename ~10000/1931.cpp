#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Time {
	int begin;
	int end;
};

bool cmp(Time f, Time s) {
	if (f.end == s.end) {
		return f.begin < s.begin;
	}
	else
		return f.end < s.end;
}

int main() {
	int n;
	cin >> n;
	vector<Time> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i].begin >> v[i].end;
	}

	sort(v.begin(), v.end(), cmp);
	int cnt = 0;
	int N = 0;

	for (int i = 0; i < v.size(); i++) {
		if (N <= v[i].begin) {
			N = v[i].end;
			cnt++;
		}
	}

	cout << cnt;
}