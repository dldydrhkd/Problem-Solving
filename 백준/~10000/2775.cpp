#include <iostream>
using namespace std;
int arr[15][15];

int main(){
	int t;
	cin >>t;
	for(int i=0; i<15; i++){
		for(int j=0; j<15; j++){
			if(i==0){
				arr[i][j]=j;
				continue;
			}
			for(int p=0; p<=j; p++){
				arr[i][j]+=arr[i-1][p];
			}
		}
	}
	while(t--){
		int k,n;
		cin >>k>>n;
		cout<<arr[k][n]<<"\n";
	}
}