#include <iostream>
#include <algorithm>
using namespace std;
int arr[1011];

int main(){
    while(1){
        int r,n;
        cin >>r>>n;
        if(n==-1 && r==-1){
            break;
        }
        for(int i=0; i<n; i++){
            cin >>arr[i];
        }
        sort(arr, arr+n);
        int i = 0;
        int j = 0;
        int cnt = 0;
        for(int k=0; k<n; k++){
            if(arr[i]+r >= arr[k]){
                j = k;
                continue;
            }
            if(arr[j]+r >= arr[k]){
                continue;
            }
            else{
                cnt++;
                i=k;
                j=k;
            }
        }
        cout<<cnt+1<<"\n";
    }
}