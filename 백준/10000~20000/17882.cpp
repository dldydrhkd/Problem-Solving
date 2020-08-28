#include <iostream>
#include <string>
using namespace std;
int arr[286401];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,p,d;
    cin >>n>>p>>d;
    string str;
    cin >>str;
    for(int i=0; i<2*n; i++){
        if(str[i%str.size()]=='Z'){
            arr[i+1]=arr[i]+1;
        }
        else{
            arr[i+1]=arr[i];
        }
    }
    int cnt=0;
    for(int i=n+1; i<=2*n; i++){
        if(arr[i]-arr[i-p]<d){
            cnt++;
        }
    }
    cout<<cnt;
}