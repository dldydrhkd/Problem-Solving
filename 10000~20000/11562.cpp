#include <iostream>
#include <algorithm>
using namespace std;
#define INF 987654321
int arr[251][251];
int n,m;

void floyd(){
    for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >>n>>m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			arr[i][j] = i == j ? 0 : INF;

	for (int i = 0; i < m; i++) {
        int u,v,w;
		cin >> u >> v >> w;
		if (w == 0) {
			arr[u][v] = 0;
			arr[v][u] = 1;
		}
		else {
			arr[u][v] = arr[v][u] = 0;
		}
	}

    floyd();

	int t;
    cin >>t;
	while (t--) {
		int a, b;
        cin >>a>>b;
        cout<<arr[a][b]<<"\n";
	}
}