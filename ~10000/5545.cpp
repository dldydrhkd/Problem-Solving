#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int arr[101];
double temp[101];

bool cmp(int a, int b){
	return a>b;
}

int main(){
	int n,a,b,c;
	cin >>n>>a>>b>>c;

	for(int i=0; i<n; i++){
		cin >>arr[i];
	}

	sort(arr,arr+n,cmp);

	int temp=c/a;
	int power=c;
	int price=a;

	for(int i=0; i<n; i++){
		power+=arr[i];
		price+=b;
		if(temp>power/price){
			break;
		}
		temp=power/price;
	}

	cout<<temp;






}