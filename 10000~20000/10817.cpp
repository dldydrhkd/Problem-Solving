#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> v;

int main(){
	
	for(int i=0; i<3; i++){
		int a;
		cin >>a;
		v.push_back(a);
	}	

	sort(v.begin(),v.end());

	cout<<v[1];
}