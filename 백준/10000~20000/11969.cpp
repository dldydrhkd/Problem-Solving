#include <iostream>
using namespace std;
int arr[100001][3];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,q;
    cin >> n>>q;
    for(int i=1; i<=n; i++){
        int a;
        cin >>a;
        for(int j=0; j<3; j++){
            if(j+1==a){
                arr[i][j]+=arr[i-1][j]+1;
            }
            else{
                arr[i][j]+=arr[i-1][j];
            }
        }
    }
    while(q--){
        int a,b;
        cin >>a>>b;
        for(int i=0; i<3; i++){
            cout<<arr[b][i]-arr[a-1][i]<<" ";
        }
        cout<<"\n";
    }
}