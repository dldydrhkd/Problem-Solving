#include <iostream>
using namespace std;
typedef long long ll;

ll cal(int a, int b){
    ll sum=1;
    while(b--){
        sum*=a;
    }
    return sum;
}

int main(){
    int t;
    cin >>t;
    while(t--){
        int a,b;
        cin >>a>>b;
        ll sum=1;
        while(b--){
            sum*=a;
            sum%=10;
        }
        if(sum==0){
            cout<<"10\n";
        }
        else{
            cout<<sum<<"\n";
        }
    }
}