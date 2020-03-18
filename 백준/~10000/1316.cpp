#include <iostream>
#include <vector>
using namespace std;
string str[101];
bool alpha[26];

bool group(string s){
	for(int i=0; i<26; i++){
		alpha[i]=false;
	}
	for(int i=0; i<s.size();){
		if(alpha[s[i]-'a']){
			return false;
		}
		else{
			char temp=s[i];
			while(temp==s[i] && i<s.size()){
				alpha[s[i]-'a']=true;
				i++;
			}
		}
	}
	return true;
}


int main(){
	int n;
	cin >>n;
	int cnt=0;
	for(int i=0; i<n; i++){
		cin >>str[i];
		if(group(str[i])){
			cnt++;
		}
	}
	cout<<cnt;
}