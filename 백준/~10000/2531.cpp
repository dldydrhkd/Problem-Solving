#include <iostream>
#include <algorithm>
using namespace std;
int arr[60020];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,d,k,c;
    cin >>n>>d>>k>>c;
    for(int i=0; i<n; i++){
        cin >>arr[i];
        arr[i+n]=arr[i];
    }
    int answer = 0;
    for(int i=0; i<n; i++){
        bool check[3001];
        int cnt=0;
        for(int j=0; j<=3000; j++){
            check[j]=false;
        }
        for(int j=0; j<k; j++){
            if(check[arr[i+j]]==false){
                check[arr[i+j]]=true;
                cnt++;
            }
        }
        if(!check[c])
            cnt++;
        answer = max(answer,cnt);
    }
    cout<<answer;
}