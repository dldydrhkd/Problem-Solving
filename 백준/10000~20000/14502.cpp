#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int n,m;
int arr[9][9];
int temp[9][9];
int cnt;
int max_cnt;
bool visited[9][9];
int x[]={0,0,-1,1};
int y[]={1,-1,0,0};

bool check(int a,int b){
	if(a>=0 && a<n && b>=0 && b<m){
		return true;
	}
	return false;
}

void bfs(){
	cnt=0;
	queue<pair<int,int>> q;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(temp[i][j]==1){
				visited[i][j]=true;
			}
			else if(temp[i][j]==2){
				visited[i][j]=true;
				q.push({i,j});
			}
			else if(temp[i][j]==0) cnt++;
			visited[i][j]=false;
		}
	}
	while(!q.empty()){
		int front_x=q.front().first;
		int front_y=q.front().second;
		q.pop();
		

		for(int i=0; i<4; i++){
			int nx=front_x+x[i];
			int ny=front_y+y[i];
			if(check(nx,ny) && temp[nx][ny]==0 && !visited[nx][ny]){
				visited[nx][ny]=true;
				q.push({nx,ny});
				cnt--;
			}
		}
	}
	max_cnt=max(max_cnt,cnt);
}

int main(){
	cin >>n>>m;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin>>arr[i][j];
			temp[i][j]=arr[i][j];
		}
	}

	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(temp[i][j]==0){
				temp[i][j]=1;
				for(int a=0; a<n; a++){
					for(int b=0; b<m; b++){
						if(temp[a][b]==0){
							temp[a][b]=1;
							for(int p=0; p<n; p++){
								for(int q=0; q<m; q++){
									if(temp[p][q]==0){
										temp[p][q]=1;
										bfs();
										temp[p][q]=0;
									}
								}
							}
							temp[a][b]=0;
						}
					}
				}
				temp[i][j]=0;
			}
		}
	}
	cout<<max_cnt;
}