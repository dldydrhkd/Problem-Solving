#include <iostream>
using namespace std;

bool arr[10000001];
long long ans[10000001];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    for(int i=2; i*i<=10000000; i++){
        int k=2;
        while(i*k<=10000000){
            arr[i*k]=true;
            k++;
        }
    }
    for(int i=2; i<=10000000; i++){
        if(arr[i]==false){
            ans[i]=ans[i-1]+1;
        }
        else{
            ans[i]=ans[i-1];
        }
    }
    int m,n;
    while(cin >>m>>n){
        cout<<ans[n]-ans[m-1]<<"\n\n";
    }
}