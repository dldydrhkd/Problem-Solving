#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
using namespace std;
int friend_num[200002];
int par[200002];

int find(int u){
	if(u == par[u]){
		return u;
	}
	return par[u] = find(par[u]);
}

void merge(int u, int v){
	u = find(u);
	v = find(v);

	if(u==v){
		return ;
	}
	if (friend_num[u] > friend_num[v]){
		par[v] = u;
		friend_num[u] += friend_num[v];
		friend_num[v] = friend_num[u];
	}
	else{
		par[u] = v;
		friend_num[v] += friend_num[u];
		friend_num[u] = friend_num[v];
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		int f;
		cin >>f;
		int cnt = 1;
		map<string,int> friend_set;
		for(int i=1; i<=2*f; i++){
			par[i]=i;
			friend_num[i]=1;
		}
		for(int i=0; i<f; i++){
			string a,b;
			cin >>a>>b;
			if(friend_set.count(a)==0){
				friend_set[a]=cnt;
				cnt++;
			}
			if(friend_set.count(b)==0){
				friend_set[b]=cnt;
				cnt++;
				
			}
			merge(find(friend_set[a]),find(friend_set[b]));
			cout<<max(friend_num[find(friend_set[a])],friend_num[find(friend_set[b])])<<"\n";
		}
	}
}