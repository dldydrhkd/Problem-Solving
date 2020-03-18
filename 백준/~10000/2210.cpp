#include <iostream>
#include <string>
using namespace std;
int x[] = { 0,0,-1,1 };
int y[] = { 1,-1,0,0 };

char arr[5][5];
bool visited[1000000];

bool check(int a, int b) {
	if (a >= 0 && a < 5 && b >= 0 && b < 5) {
		return true;
	}
	return false;
}

void func(string str, int a, int b) {
	string temp= str + arr[a][b];
	if (temp.size() == 6) {
		int num = stoi(temp);
		visited[num] = true;
		return;
	}

	for (int i = 0; i < 4; i++) {
		int nx = a + x[i];
		int ny = b + y[i];

		if (check(nx, ny)) {
			func(temp, nx, ny);
		}
	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> arr[i][j];
		}
	}
	int cnt = 0;

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			func("", i, j);
		}
	}
	for (int i = 0; i <= 999999; i++) {
		if (visited[i] == true) {
			cnt++;
		}
	}

	cout << cnt;


}