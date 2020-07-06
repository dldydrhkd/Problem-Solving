#include <iostream>
#include <algorithm>
using namespace std;
int arr[501][501];
int main(){
    int a;
    cin >>a;

    for(int i=0; i<a; i++){
        for(int j=0; j<i+1; j++){
            cin >>arr[i][j];
        }
    }

    for(int i=1; i<a; i++){
        for(int j=0; j<i+1; j++){
            if(j==0){
                arr[i][j]+=arr[i-1][j];
            }
            else if(j==i){
                arr[i][j]+=arr[i-1][j-1];
            }
            else{
                arr[i][j]+=max(arr[i-1][j-1],arr[i-1][j]);
            }
        }
    }
    
    int sum=0;
    for(int i=0; i<a; i++){
        sum=max(sum,arr[a-1][i]);
    }

    cout<<sum;
}