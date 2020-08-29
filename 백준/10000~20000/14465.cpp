#include <iostream>
#include <algorithm>
using namespace std;
int arr[100001];
int check[100001];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n,k,b;
    cin >>n>>k>>b;
    for(int i=1; i<=b; i++){
        int a;
        cin >>a;
        check[a]=true;
    }
    for(int i=1; i<=n; i++){
        if(check[i]){
            arr[i]=arr[i-1]+1;
        }
        else{
            arr[i]=arr[i-1];
        }
    }
    int answer=1e9+7;
    for(int i=1; i<=n-k+1; i++){
        answer=min(arr[i+k-1]-arr[i-1],answer);
    }
    cout<<answer;
}