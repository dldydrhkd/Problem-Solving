#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int n,k;
typedef long long ll;
vector<pair<ll,ll>> ruby;
vector<ll> bag;

int main(){
	cin>>n>>k;
	for(int i=0; i<n; i++){
		int a,b;
		cin >>a>>b;
		ruby.push_back({a,b});
	}
	sort(ruby.begin(),ruby.end());

	for(int i=0; i<k; i++){
		int a;
		cin >>a;
		bag.push_back(a);
	}
	sort(bag.begin(),bag.end());
	priority_queue<int> pq;
	long long result=0;
	int idx=0;
	for(int i=0; i<k; i++){
		while(idx<n && bag[i]>=ruby[idx].first){
			pq.push(ruby[idx].second);
			idx++;
		}
		if(!pq.empty()){
			result+=pq.top();
			pq.pop();
		}
	}
	cout<<result<<"\n";
}