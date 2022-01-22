#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> arr[32001];
bool visited[32001];

stack<int> st;

void dfs(int here) {
    visited[here] = true;
    for (int i = 0; i < arr[here].size(); i++) {
        int there = arr[here][i];
        if (visited[there]) {
            continue;
        }
        dfs(there);
    }
    st.push(here);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        arr[a].push_back(b);
    }

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }
    while (st.size()) {
        cout << st.top() << " ";
        st.pop();
    }
}
