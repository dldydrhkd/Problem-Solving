#include <iostream>
#include <vector>
using namespace std;
int arr[1000010];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,q;
    cin >>n>>q;
    for(int i=1; i<=n; i++){
        cin >>arr[i];
        arr[i] ^= arr[i-1];
    }
    int answer =0;
    while(q--){
        int s,e;
        cin >>s>>e;
        int sum= arr[e]^arr[s-1];
        answer^=sum;
    }
    cout<<answer;
}