#include <iostream>
using namespace std;

int main(){
    int n;
    cin >>n;
    int cnt = 1;
    int i = n/2;
    int j = n/2 + 1;
    while(i>=1 && j>=1){
        int sum=(i+j)*(j-i+1)/2;
        if(sum==n){
            cnt++;
            i--;
        }
        else if(sum<n){
            i--;
        }
        else{
            j--;
        }
    }
    cout<<cnt;
}