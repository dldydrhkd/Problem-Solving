#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int arr[101][101];
int trace[101][101];
int cnt;

void Find(int a, int b){
	if(trace[a][b]!=0){
		cnt++;
		Find(a,trace[a][b]);
		Find(trace[a][b],b);
	}
}

void route(int a,int b){
	if(trace[a][b]!=0){
		route(a,trace[a][b]);
		cout<<trace[a][b]<<" ";
		route(trace[a][b],b);
	}
}

int main(){
	int n,m;
	cin >>n>>m;

	for(int i=0; i<m; i++){
		int a,b,c;
		cin >>a>>b>>c;
		if(arr[a][b]){
			arr[a][b]=min(arr[a][b],c);
		}
		else{
			arr[a][b]=c;
		}
	}
	
	for(int k=1; k<=n; k++){
		for(int i=1; i<=n; i++){
			for(int j=1; j<=n; j++){
				if(i==j) {
					continue;
				}
				else if(arr[i][k] && arr[k][j]){
					if(arr[i][j]==0){
						arr[i][j]=arr[i][k]+arr[k][j];
						trace[i][j]=k;
					}
					else if(arr[i][j] > arr[i][k]+arr[k][j]){
						arr[i][j]=arr[i][k]+arr[k][j];
						trace[i][j]=k;
					}
				}
			}
		}
	}

	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			cout<<arr[i][j]<<" ";
		}
		cout<<"\n";
	}

	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			if(arr[i][j]==0){
				cout<<"0\n";
			}
			else{
				cnt=2;
				Find(i,j);
				cout<<cnt<<" ";
				cout<<i<<" ";
				route(i,j);
				cout<<j<<"\n";
			}
		}
	}

}