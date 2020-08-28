#include <iostream>
#include <algorithm>
using namespace std;
int arr[101];

int main(){
    int n,k;
    cin >>n>>k;
    for(int i=1; i<=n; i++){
        cin >>arr[i];
        arr[i]+=arr[i-1];
    }
    int answer=-987654321;
    for(int i=1; i<=n-k+1; i++){
        int sum=arr[i+k-1]-arr[i-1];
        answer=max(answer,sum);
    }
    cout<<answer;
}