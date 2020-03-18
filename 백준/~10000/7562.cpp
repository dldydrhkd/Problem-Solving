#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
int l;
int arr[301][301];
bool visited[301][301];
int x[]={-1,1,-1,1,2,-2,2,-2};
int y[]={2,2,-2,-2,1,-1,-1,1};


bool check(int a, int b){
	if(a>=0 && a<l && b>=0 && b<l){
		return true;
	}
	return false;
}

int bfs(int a, int b, int c, int d){
	int cnt=0;
	for(int i=0; i<l; i++){
		for(int j=0; j<l; j++){
			visited[i][j]=false;
		}
	}
	queue<pair<int,int>> q;
	q.push({a,b});
	visited[a][b]=true;
	
	while(!q.empty()){
		int size=q.size();
		while(size--){
			int front_x=q.front().first;
			int front_y=q.front().second;
			q.pop();
			if(front_x==c && front_y==d){
				return cnt;
			}
			for(int i=0; i<8; i++){
				int nx=front_x+x[i];
				int ny=front_y+y[i];

				if(!visited[nx][ny] && check(nx,ny)){
					visited[nx][ny]=true;
					q.push({nx,ny});
				}
			}
		}
		cnt++;
	}
	return cnt;
}

int main(){
	int t;
	cin >>t;
	while(t--){
		int a,b,c,d;
		cin >>l;
		cin >>a>>b>>c>>d;
		cout<<bfs(a,b,c,d)<<"\n";
	}
}