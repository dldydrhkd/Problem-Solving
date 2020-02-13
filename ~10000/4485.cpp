#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int arr[126][126];
bool visited[126][126];
int x[] = { 0,0,-1,1 };
int y[] = { 1,-1,0,0 };


int main() {
	int t = 0;
	while (1) {
		t++;
		int n;
		cin >> n;
		if (n == 0) {
			return 0;
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> arr[i][j];
				visited[i][j] = false;
			}
		}

		priority_queue<pair<int, pair<int, int>>> pq;

		pq.push({ -arr[0][0],{0,0} });
		visited[0][0] = true;

		while (!pq.empty()) {
			int now_x = pq.top().second.first;
			int now_y = pq.top().second.second;
			int now_val = -pq.top().first;
			pq.pop();

			if (now_x == n - 1 && now_y == n - 1) {
				cout << "Problem " << t << ": " << now_val << "\n";
				break;
			}

			for (int i = 0; i < 4; i++) {
				int nx = now_x + x[i];
				int ny = now_y + y[i];

				if (nx >= 0 && nx < n && ny >= 0 && ny < n && !visited[nx][ny]) {
					pq.push({ -(now_val + arr[nx][ny]),{nx,ny} });
					visited[nx][ny] = true;
				}
			}
		}



	}
}