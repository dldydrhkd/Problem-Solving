#include <iostream>
using namespace std;

int main(){
	int t;
	cin >>t;
	while(t--){
		int h,w,n;
		cin >>h>>w>>n;

		int temp=n/h;		//호
		int remain=n%h;		//층

		if(remain==0){
			cout<<h;
			if(temp<=9){
				cout<<"0"<<temp<<"\n";
			}
			else{
				cout<<temp<<"\n";
			}
		}
		else{
			cout<<remain;
			if(temp+1<=9){
				cout<<"0"<<temp+1<<"\n";
			}
			else{
				cout<<temp+1<<"\n";
			}
		}
	}
}