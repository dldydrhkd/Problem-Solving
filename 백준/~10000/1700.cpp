#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define INF 987654321
int arr[101];
int plug[101];


int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,k;
	cin >>n>>k;

	for(int i=0; i<k; i++){
		cin >>arr[i];
	}
	int cnt=0;

	for(int i=0; i<k; i++){
		bool check=false;

		for(int j=0; j<n; j++){
			if(plug[j]==0){			//empty space
				plug[j]=arr[i];		
				check=true;
				break;
			}
			if(plug[j]==arr[i]){
				check=true;			//same plug
				break;
			}
		}

		if(check){
			continue;
		}
		int late=-1,idx=0;
		bool chk=false;
		for(int j=0; j<n; j++){			//full
			int latest=INF, temp=0;
			for(int p=i+1; p<k; p++){
				if(plug[j]==arr[p]){
					latest=min(latest,p);
					temp=j;
				}
			}
			if(latest==INF){			//change with not using anymore
				plug[j]=arr[i];
				cnt++;
				chk=true;
				break;
			}
			if(late<latest){
				late=latest;
				idx=temp;
			}
		}
		if(late!=-1 && chk==false){
			plug[idx]=arr[i];
			cnt++;
		}
	}
	cout<<cnt;
}å