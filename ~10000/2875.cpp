#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int girl,boy,k;
	cin >>girl>>boy>>k;
	int grp=0;

	for(int i=0; i<boy; i++){
		if(girl==0 || girl==1){
			break;
		}
		girl-=2;
		grp++;
	}
	int remain=girl+boy-grp;
	k-=remain;
	while(k>0){
		grp--;
		k-=3;
	}

	cout<<grp;
	
}