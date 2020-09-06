#include <iostream>
#include <algorithm>
using namespace std;
string arr[10001];

int main(){
    int t;
    cin >>t;
    while(t--){
        int a;
        cin >>a;
        for(int i=0; i<a; i++){
            cin >>arr[i];
        }
        sort(arr,arr+a);
        bool check=false;
        for(int i=0; i<a-1; i++){
            if(arr[i].size()>arr[i+1].size()) continue;
            check = true;
            for(int j=0; j<arr[i].size(); j++){
                if(arr[i][j]!=arr[i+1][j]){
                    check=false;
                    break;
                }
            }
            if(check){
                cout<<"NO\n";
                break;
            }
        }
        if(!check){
            cout<<"YES\n";
        }
    }
}