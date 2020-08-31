#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
typedef long long ll;
ll arr[101][101];
int n,m;

int main(){
    cin >>n>>m;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            int a;
            scanf("%1d",&a);
            arr[i][j]=arr[i-1][j]+arr[i][j-1]-arr[i-1][j-1]+a;
        }
    }
    long long sum=0;
    for(int i=1; i<=n-2; i++){
        for(int j=i+1; j<=n-1; j++){
            ll first = arr[i][m];
            ll second = arr[j][m]-first;
            ll third = arr[n][m]-arr[j][m];
            sum=max(sum, first*second*third);
        }
    }
    for(int i=1; i<=m-2; i++){
        for(int j=i+1; j<=m-1; j++){
            ll first = arr[n][i];
            ll second = arr[n][j]-first;
            ll third = arr[n][m]-arr[n][j];
            sum=max(sum, first*second*third);
        }
    }
    for(int i=1; i<=n-1; i++){
        for(int j=1; j<=m-1; j++){
            sum=max(arr[i][j]*(arr[i][m]-arr[i][j])*(arr[n][m]-arr[i][m]),sum);
            sum=max(arr[n][j]*(arr[i][m]-arr[i][j])*(arr[n][m]-arr[i][m]-arr[n][j]+arr[i][j]),sum);
            sum=max(arr[i][m]*(arr[n][j]-arr[i][j])*(arr[n][m]-arr[i][m]-arr[n][j]+arr[i][j]),sum);
            sum=max(arr[i][j]*(arr[n][j]-arr[i][j])*(arr[n][m]-arr[n][j]),sum);
        }
    }
    cout<<sum;
}