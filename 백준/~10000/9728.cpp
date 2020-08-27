#include <iostream>
using namespace std;
int arr[20001];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >>t;
    int index=0;
    while(index<t){
        int n,m;
        cin >>n>>m;
        int i = 0;
        int j = n-1;
        for(int k=0; k<n; k++){
            cin >>arr[k];
        }
        int cnt = 0;
        while(i<j){
            if(arr[i]+arr[j]==m){
                cnt++;
                i++;
            }
            else if(arr[i]+arr[j]>m){
                j--;
            }
            else{
                i++;
            }
        }
        cout<<"Case #"<<index+1<<": "<<cnt<<"\n";
        index++;
    }
}