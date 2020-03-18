#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n,m;
typedef long long ll;
vector<ll> v;

int main(){
	cin>>n>>m;
	for(int i=0; i<n; i++){
		int a;
		cin >>a;
		v.push_back(a);
	}

	sort(v.begin(),v.end());

	for(int i=0; i<m; i++){
		ll sum=v[0]+v[1];
		v[0]=sum;
		v[1]=sum;
		sort(v.begin(),v.end());
	}
	ll ans=0;
	for(int i=0; i<n; i++){
		ans+=v[i];
	}

	cout<<ans;



}