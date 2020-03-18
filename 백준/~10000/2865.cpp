#include <stdio.h>
#include <queue>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n,m,k;
vector<double> arr[101];

bool cmp(double a, double b){
	return a>b;
}

int main(){
	scanf("%d %d %d",&n,&m,&k);


	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			int a;
			double b;
			cin >>a>>b;
			arr[a].push_back(b);
		}
	}


	priority_queue<double> pq;
	for(int i=1; i<=n; i++){
		sort(arr[i].begin(),arr[i].end(),cmp);
		pq.push(arr[i][0]);
	}
	
	double sum=0;

	for(int i=0; i<k; i++){
		sum+=pq.top();
		pq.pop();
	}

	printf("%.1f",sum);

}