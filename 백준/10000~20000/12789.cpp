#include <iostream>
#include <stack>
using namespace std;


int arr[1001];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	stack<int> st;
	stack<int> que;

	for (int i = n-1; i >=0; i--) {
		st.push(arr[i]);
	}

	int k = 0;
	while (1) {
		if (k == n) {
			cout << "Nice";
			break;
		}
		else {
			if (!st.empty()) {
				if (st.top() == k + 1) {
					st.pop();
					k++;
				}
				else if (st.top() != k + 1) {
					if (!que.empty() && que.top() == k + 1) {
						que.pop();
						k++;
					}
					else {
						que.push(st.top());
						st.pop();
					}
				}				
			}
			else{
				if (!que.empty() && que.top() == k + 1) {
					que.pop();
					k++;
				}
				else{
					cout << "Sad" << endl;
					return 0;
				}
			}
		}
	}
	return 0;
}