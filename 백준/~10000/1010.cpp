#include <iostream>
using namespace std;
typedef long long ll;
ll arr[30][30];

ll cal(int a,int b){
    if(a==b){
        return 1;
    }
    if(b==0){
        return 1;
    }
    if(arr[a][b]){
        return arr[a][b];
    }
    return arr[a][b]=cal(a-1,b-1)+cal(a-1,b);
}

int main(){
    int t;
    cin >>t;
    while(t--){
        int a,b;
        cin >>a>>b;
        ll temp = cal(b,a);
        cout<<temp<<"\n";
    }
}