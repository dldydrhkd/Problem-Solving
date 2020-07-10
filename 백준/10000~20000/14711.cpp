#include <iostream>
using namespace std;
int x[]={0,0,-1};
int y[]={1,-1,0};
char arr[1001][1001];
int n;

bool check(int a, int b){
    if(a>=0 && a<n && b>=0 && b<n){
        return true;
    }
    return false;
}

int main(){
    cin >>n;
    for(int i=0; i<n; i++){
        cin>>arr[0][i];
    }
    for(int i=1; i<n; i++){
        for(int j=0; j<n; j++){
            int cnt=0;
            if(arr[i-1][j]=='.'){
                for(int k=0; k<3; k++){
                    int nx=i-1+x[k];
                    int ny=j+y[k];
                    if(check(nx,ny)){
                        if(arr[nx][ny]=='#'){
                            cnt++;
                        }
                    }
                }
                if(cnt%2==0){
                    arr[i][j]='.';
                }
                else{
                    arr[i][j]='#';
                }
            }
            else if(arr[i-1][j]=='#'){
                for(int k=0; k<3; k++){
                    int nx=i-1+x[k];
                    int ny=j+y[k];
                    if(check(nx,ny)){
                        if(arr[nx][ny]=='#'){
                            cnt++;
                        }
                    }
                }
                if(cnt%2==0){
                    arr[i][j]='.';
                }
                else{
                    arr[i][j]='#';
                }
            }
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<arr[i][j];
        }
        cout<<"\n";
    }

}