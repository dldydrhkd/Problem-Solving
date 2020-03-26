#include <iostream>
using namespace std;



char black[8][8]={
				{'B','W','B','W','B','W','B','W'},
				{'W','B','W','B','W','B','W','B'},
				{'B','W','B','W','B','W','B','W'},
				{'W','B','W','B','W','B','W','B'},
				{'B','W','B','W','B','W','B','W'},
				{'W','B','W','B','W','B','W','B'},
				{'B','W','B','W','B','W','B','W'},
				{'W','B','W','B','W','B','W','B'}
				};

char white[8][8]={
				{'W','B','W','B','W','B','W','B'},
				{'B','W','B','W','B','W','B','W'},
				{'W','B','W','B','W','B','W','B'},
				{'B','W','B','W','B','W','B','W'},
				{'W','B','W','B','W','B','W','B'},
				{'B','W','B','W','B','W','B','W'},
				{'W','B','W','B','W','B','W','B'},
				{'B','W','B','W','B','W','B','W'}
				};

char arr[51][51];

int main(){
	int n,m;
	cin >>n>>m;

	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin >>arr[i][j];
		}
	}
	int res=987654321;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){

			if(i+8>n || j+8>m){
				continue;
			}
			int cnt1=0;
			int cnt2=0;
			for(int k=0; k<8; k++){
				for(int q=0; q<8; q++){
					if(arr[k+i][q+j]!=black[k][q]){
						cnt1++;
					}
					if(arr[k+i][q+j]!=white[k][q]){
						cnt2++;
					}
				}
			}
			res=min(cnt1,res);
			res=min(res,cnt2);
		}
	}
	cout<<res;
}