#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

#define INF 987654321

using namespace std;
vector<pair<int, int>> ver[20001];
int V, E;
int start;
int visited[20001];


int main() {

	cin >> V >> E >> start;

	for (int i = 1; i <= V; i++) {
		visited[i] = INF;
	}

	for (int i = 0; i < E; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		ver[u].push_back({ v,w });

	}

	priority_queue<pair<int, int>> pq;
	
	pq.push({ 0,start });
	visited[start] = 0;
	while (!pq.empty()) {
		int vertex = pq.top().second;
		int value = -pq.top().first;
		pq.pop();
		if (visited[vertex] < value) {
			continue;
		}

		for (int i = 0; i < ver[vertex].size(); i++) {
			int next_ver = ver[vertex][i].first;
			int next_val = ver[vertex][i].second;
			if (visited[next_ver]>(next_val+value)) {
				visited[next_ver] = next_val + value;
				pq.push({ -(next_val + value),next_ver });
			}
		}
	}

	for (int i = 1; i <= V; i++) {
		if (visited[i] == INF) {
			cout << "INF\n";
		}
		else {
			cout << visited[i] << "\n";
		}
		
	}

}