#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int arr[9][9];
bool visited[3][3][10];
bool garo[9][10];
bool sero[9][10];


void dfs(int cnt) {
	if (cnt == 81) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << arr[i][j] << " ";
			}
			cout << "\n";
		}
		exit(0);
	}
	
	int x = cnt / 9;
	int y = cnt % 9;

	if (arr[x][y]) {
		dfs(cnt + 1);
	}
	else {
		for (int i = 1; i <= 9; i++) {
			if (!garo[x][i] && !sero[y][i] && !visited[x/3][y/3][i]) {
				arr[x][y] = i;
				garo[x][i] = true;
				sero[y][i] = true;
				visited[x/3][y/3][i] = true;
				dfs(cnt + 1);
				arr[x][y] = 0;
				garo[x][i] = false;
				sero[y][i] = false;
				visited[x/3][y/3][i] = false;
			}
		}
	}


}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> arr[i][j];
			garo[i][arr[i][j]] = true;
			sero[j][arr[i][j]] = true;
			visited[i / 3][j / 3][arr[i][j]] = true;
		}
	}

	dfs(0);
	
}