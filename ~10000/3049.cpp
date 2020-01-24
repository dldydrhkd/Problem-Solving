#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	cout << n * (n - 1)*(n - 2)*(n - 3) / 24;

	//교점을 만들려면 4개의 점이 필요하므로
	//결국 사각형을 만들 수 있는개수가 답이다
}