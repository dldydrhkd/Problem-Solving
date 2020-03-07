#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
int arr[1001];

int main(){
	cin>>n;
	for(int i=0; i<n; i++){
		cin >>arr[i];
	}
	sort(arr,arr+n);
	
	if(arr[0]!=1){
		cout<<1;
		return 0;
	}

	int sum=arr[0];
	for(int i=1; i<n; i++){
		if(arr[i]>sum+1){
			break;
		}
		sum+=arr[i];
	}
	cout<<sum+1;
}