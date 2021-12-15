#include <iostream>
using namespace std;
int par[1000001];
int ran[1000001];

int find(int u){
	if(u == par[u])
		return u;
	return par[u] = find(par[u]);
}

void uni(int a, int b){
	a = find(a);
	b = find(b);

	if (a == b) return;
	if(ran[a] > ran[b]){
		swap(a,b);
	}
	par[a] = b;
	if(ran[a] == ran[b]) ran[b]++;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	cin >>n >>m;
	for(int i=1; i<=n; i++){
		par[i] = i;
	}
	for(int i=0; i<=n; i++){
		ran[i] = 1;
	}
	for(int i=0; i<m; i++){
		int a,b,c;
		cin >>a>>b>>c;
		if(a==0){
			uni(b,c);
		}
		if(a==1){
			if(find(b)==find(c)){
				cout<<"YES\n";
			}
			else{
				cout<<"NO\n";
			}
		}
	}
}