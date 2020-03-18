#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool func(int a){
	string str="";
	while(a!=0){
		str+=char(a%10+'0');
		a/=10;
	}
	int temp=str[1]-str[0];
	bool chk=true;
	for(int i=2; i<str.size(); i++){
		if(temp!=str[i]-str[i-1]){
			chk=false;
			break;
		}
	}

	return chk;
	
}

int main(){
	int n;
	cin >>n;
	int cnt=99;

	if(n<=99){
		cout<<n;
		return 0;
	}
	else{
		for(int i=100; i<=n; i++){
			if(func(i)){
				cnt++;
			}
		}
		cout<<cnt;
	}
}