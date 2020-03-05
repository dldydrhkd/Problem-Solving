#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
vector<int> v;

bool cmp(int a, int b){
	return b<a;
}

int main(){
	string num;
	cin >>num;
	ll sum=0;
	bool check=false;
	for(int i=0; i<num.size(); i++){
		sum+=num[i]-'0';
		if(num[i]=='0'){
			check=true;
		}
	}
	if(check && sum%3==0){
		for(int i=0; i<num.size(); i++){
			v.push_back(num[i]-'0');
		}
		sort(v.begin(),v.end(),cmp);
		string str="";
		for(int i=0; i<v.size(); i++){
			str+=char(v[i]+'0');
		}
		cout<<str;
	}
	else{
		cout<<"-1\n";
	}
}