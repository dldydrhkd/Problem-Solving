#include <iostream>
using namespace std;
int arr[100001];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >>n;
    for(int i=1; i<=n; i++){
        cin >>arr[i];
        arr[i]+=arr[i-1];
    }
    int q;
    cin >>q;
    while(q--){
        int a,b;
        cin >>a>>b;
        cout<<arr[b]-arr[a-1]<<"\n";
    }
}