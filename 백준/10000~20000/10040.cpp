#include <iostream>
using namespace std;
int arr[1001];
int cnt[1001];

int main(){
    int n,m;
    cin >>n>>m;
    for(int i=1; i<=n; i++){
        cin >>arr[i];
    }
    for(int i=0; i<m; i++){
        int b;
        cin >>b;
        for(int j=1; j<=n; j++){
            if(b>=arr[j]){
                cnt[j]++;
                break;
            }
        }
    }
    int a=0;
    int answer;
    for(int i=1; i<=n; i++){
        if(a<cnt[i]){
            answer=i;
            a=cnt[i];
        }
    }
    cout<<answer;
}