#include <iostream>
#include <algorithm>
using namespace std;
int arr[1000010];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,k;
    cin >>n>>k;
    for(int i=0; i<k; i++){
        int a,b;
        cin >>a>>b;
        arr[a]++;
        arr[b+1]--; 
    }
    for(int i=1; i<=n; i++){
        arr[i]+=arr[i-1];
    }
    sort(arr, arr+n+1);
    cout<<arr[n/2+1];
}