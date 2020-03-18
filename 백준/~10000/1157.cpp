#include <iostream>
#include <string>
using namespace std;
int alpha[26];


int main(){
	string str;
	cin >>str;
	for(int i=0; i<str.size(); i++){
		int temp=str[i]-'a';
		if(temp<0){
			temp=str[i]-'A';
			alpha[temp]++;
		}
		else{
			alpha[temp]++;
		}
	}
	
	int cnt=-1;
	int idx=0;

	for(int i=0; i<26; i++){
		if(cnt<alpha[i]){
			cnt=alpha[i];
			idx=i;
		}
	}
	for(int i=0; i<26; i++){
		if(cnt==alpha[i] && idx!=i){
			cout<<"?";
			return 0;
		}
	}

	cout<<char(idx+'A');
}