#include <iostream>
using namespace std;
typedef long long ll;
#define MOD 16769023

int main(){
    int n;
    cin >>n;
    int answer=1;
    if(n%2==0){
        n=n/2;
    }
    else{
        n=n/2+1;
    }
    for(int i=1; i<=n; i++){
        answer*=2;
        answer%=MOD;
    }
    cout<<answer;
}


