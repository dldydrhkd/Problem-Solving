#include <iostream>
using namespace std;
char arr[10001][501];
int x[]={-1,0,1};
int y[]={1,1,1};
int r,c;
int cnt;

bool check(int a, int b){
    if(0<=a && a<r && 0<=b && b<c){
        return true;
    }
    return false;
}

bool dfs(int a, int b){
    arr[a][b]='x';
    if(b==c-1){
        cnt++;
        return true;
    }
    for(int i=0; i<3; i++){
        int nx=a+x[i];
        int ny=b+y[i];
        if(arr[nx][ny]=='.' && check(nx,ny)){
            if(dfs(nx,ny)) return true;
        }
    }
    return false;
}

int main(){
    cin >>r>>c;
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cin >>arr[i][j];
        }
    }
    for(int i=0; i<r; i++){
        dfs(i,0);
    }
    cout<<cnt;

}