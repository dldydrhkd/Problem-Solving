#include <iostream>
#include <algorithm>

using namespace std;
int n;
int arr[501][501];
int visited[501][501];
int x[] = {0,0,-1,1};
int y[] = {-1,1,0,0};

bool check(int a, int b){
    if(a>=0 && a<n && b>=0 && b<n){
        return true;
    }
    return false;
}

int solve(int a, int b){
    if(!check(a,b)){
        return 0;
    }
    if(visited[a][b]==-1){
        visited[a][b]=1;
        for(int i=0; i<4; i++){
            int nx = a+x[i];
            int ny = b+y[i];
            if(check(nx,ny)){
                if(arr[a][b]>arr[nx][ny]){
                    visited[a][b] = max(visited[a][b], solve(nx,ny)+1);
                }
            }
        }
    }
    return visited[a][b];
}

int main(){
    cin >>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            visited[i][j]=-1;
        }
    }
    int day = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            day = max(day,solve(i,j));
        }
    }
    cout<<day<<"\n";
}