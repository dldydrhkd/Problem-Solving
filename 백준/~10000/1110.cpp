#include <iostream>
using namespace std;
int n;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	int origin=n;
	int cnt=0;

	do{
		int a=n/10, b=n%10;
		int sum=a+b;
		n=b*10+sum%10;
		cnt++;
	}
	while(n!=origin);

	cout<<cnt;
}