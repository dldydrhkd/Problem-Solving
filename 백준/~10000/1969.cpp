#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
char str[1001][51];
char ans[51];
int alpha[26];

int main(){
	int n,m;
	cin>>n>>m;

	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin >>str[i][j];
		}
	}

	for(int j=0; j<m; j++){
		for(int i=0; i<26; i++){
			alpha[i]=0;
		}
		for(int i=0; i<n; i++){
			int temp=str[i][j]-'A';
			alpha[temp]++;
		}
		pair<int,int> MAX={0,0};
		for(int i=0; i<26; i++){
			if(MAX.first<alpha[i]){
				MAX.first=alpha[i];
				MAX.second=i;
			}
			else if(MAX.first==alpha[i] && MAX.second>i){
				MAX.second=i;
			}
		}
		ans[j]=char(MAX.second+'A');
	}


	for(int i=0; i<m; i++){
		cout<<ans[i];
	}
	cout<<"\n";
	int cnt=0;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(ans[j]!=str[i][j]){
				cnt++;
			}
		}
	}
	cout<<cnt;

}