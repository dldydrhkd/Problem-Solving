#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
vector<int> v[1000001];
bool visited[1000001];
int dp[1000001][2];
vector<int> tree[1000001];

int dfs(int cur, int state){
    if (dp[cur][state] != -1) return dp[cur][state];
    if (state == 1){
        dp[cur][state] = 1;
        for(int i=0; i<tree[cur].size(); i++){
            int next = tree[cur][i];
            dp[cur][state] += min(dfs(next,0), dfs(next,1));
        }
    }
    else{
        dp[cur][state] = 0;
        for(int i=0; i<tree[cur].size(); i++){
            int next = tree[cur][i];
            dp[cur][state] += dfs(next, 1);
        }
    }
    return dp[cur][state];
}

void make_tree(int cur){
    visited[cur] = true;
    for(int i=0; i<v[cur].size(); i++){
        int next = v[cur][i];
        if(!visited[next]){
            tree[cur].push_back(next);
            make_tree(next);
        }
    }
}

int main(){
    int n;
    cin >>n;
    for(int i=0; i<n-1; i++){
        int a,b;
        cin >>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    memset(dp, -1, sizeof(dp));
    make_tree(1);
    int result1 = dfs(1,0);
    int result2 = dfs(1,1);

    cout<<min(result1, result2)<<"\n";
}