#include <iostream>
#include <queue>
using namespace std;
int x[]={0,0,1,-1};
int y[]={1,-1,0,0};
char arr[501][501];
int n,m,r1,c1,r2,c2;
bool visit[501][501];
bool ans;

bool check(int x, int y){
    if(x>=1 && x<=n && y>=1 && y<=m){
        return true;
    }
    return false;
}

int main(){
    cin >>n>>m;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin >>arr[i][j];
        }
    }
    cin >>r1>>c1>>r2>>c2;

    queue<pair<int,int>> q;
    q.push({r1,c1});

    while(!q.empty()){
        int curx=q.front().first;
        int cury=q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            int nx=curx+x[i];
            int ny=cury+y[i];

            if(arr[nx][ny]=='X' && !visit[nx][ny] && check(nx,ny)){
                if(nx==r2 && ny==c2){
                    cout<<"YES\n";
                    return 0;
                }
                else{
                    visit[nx][ny]=true;
                    continue;
                }
            }
            else if(arr[nx][ny]=='.' && !visit[nx][ny] && check(nx,ny)){
                arr[nx][ny]='X';
                q.push({nx,ny});
            }
        }
    }
    cout<<"NO\n";
}