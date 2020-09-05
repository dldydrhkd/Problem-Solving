#include <iostream>
using namespace std;

int main(){
    int n;
    cin >>n;
    int p=100;
    int q=100;
    for(int i=0; i<n; i++){
        int a,b;
        cin >>a>>b;
        if(a<b) p-=b;
        else if(a>b) q-=a;
    }
    cout<<p<<"\n";
    cout<<q<<"\n";
}