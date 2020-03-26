#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <math.h>
using namespace std;
int arr[51][51];

int n,m;

int main(){
	cin >>n>>m;

	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			scanf("%1d",&arr[i][j]);
		}
	}

	int res=1;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			int cnt=1;

			while(i+cnt<n && j+cnt<m){
				if(arr[i][j]==arr[i+cnt][j+cnt]){
					if(arr[i][j]==arr[i][j+cnt]&&arr[i][j]==arr[i+cnt][j]){
						int a=pow(cnt+1,2);
						res=max(res,a);
					}
					
				}
				
				cnt++;
			}
		}
	}
	cout<<res;


}