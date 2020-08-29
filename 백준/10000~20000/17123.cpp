#include <iostream>
using namespace std;
int arr[1002][1002];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;

    while(t--){
        int n,m;
        cin >>n>>m;
        for(int i=1; i<=n+1; i++){
            for(int j=1; j<=n+1; j++){
                arr[i][j]=0;
            }
        }
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                cin >>arr[i][j];
                arr[i][n+1]+=arr[i][j];
                arr[n+1][j]+=arr[i][j];
            }
        }
        for(int i=0; i<m; i++){
            int a,b,c,d,e;
            cin >>a>>b>>c>>d>>e;
            int sum_row=e*(d-b+1);
            int sum_col=e*(c-a+1);
            for(int j=a; j<=c; j++){
                arr[j][n+1]+=sum_row;
            }
            for(int j=b; j<=d; j++){
                arr[n+1][j]+=sum_col;
            }
        }
        for(int i=1; i<=n; i++){
            cout<<arr[i][n+1]<<" ";
        }
        cout<<"\n";
        for(int i=1; i<=n; i++){
            cout<<arr[n+1][i]<<" ";
        }
        cout<<"\n";
    }
}