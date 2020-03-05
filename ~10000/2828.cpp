#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n,m;
vector<int> v;

int main(){
	cin >>n>>m;
	int k;
	cin >>k;

	for(int i=0; i<k; i++){
		int apple;
		cin >>apple;
		v.push_back(apple);
	}
	int move=0;
	int start=1;
	int end=m;
	for(int i=0; i<k; i++){
		if(start<=v[i] && v[i]<=end){
			continue;
		}
		else{
			if(v[i]>end){
				int cnt=v[i]-end;
				move+=cnt;
				start+=cnt;
				end+=cnt;
			}
			else if(v[i]<start){
				int cnt=start-v[i];
				move+=cnt;
				start-=cnt;
				end-=cnt;
			}
		}
	}
	cout<<move;
}