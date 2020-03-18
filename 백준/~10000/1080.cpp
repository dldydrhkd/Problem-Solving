#include <iostream>
#include <vector>
using namespace std;
int n,m;
int a[51][51];
int b[51][51];
bool cmp[51][51];
int cnt=0;

void func(int x, int y){

	if(x+3>n || y+3>m){
		return;
	}

	for(int i=x; i<x+3; i++){
		for(int j=y; j<y+3; j++){
			if(cmp[i][j]==false){
				cmp[i][j]=true;
			}
			else{
				cmp[i][j]=false;
			}
		}
	}

	cnt++;
	
}

int main(){
	cin >>n>>m;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			char temp;
			cin >>temp;
			if(temp=='0'){
				a[i][j]=0;
			}
			else{
				a[i][j]=1;
			}
		}
	}

	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			char temp;
			cin >>temp;
			if(temp=='0'){
				b[i][j]=0;
			}
			else{
				b[i][j]=1;
			}
		}
	}

	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(a[i][j]!=b[i][j]){
				cmp[i][j]=false;
			}
			else{
				cmp[i][j]=true;
			}
		}
	}

	if(n<3 || m<3){
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				if(cmp[i][j]==false){
					cout<<"-1\n";
					return 0;
				}
			}
		}
		cout<<cnt;
		return 0;
	}

	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(cmp[i][j]==false){
				func(i,j);
			}
		}
	}

	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(cmp[i][j]==false){
				cout<<"-1\n";
				return 0;
			}
		}
	}
	cout<<cnt;
}