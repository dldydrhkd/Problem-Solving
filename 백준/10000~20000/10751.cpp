#include <iostream>
#include <string>
typedef long long ll;
using namespace std;

int main(){
    int n;
    cin >>n;
    string str;
    cin >>str;
    ll C=0;
    ll CO=0;
    ll cow=0;
    int i =0;
    while(str[i]){
        if(str[i]=='C')
            C++;
        if(str[i]=='O')
            CO+=C;
        if(str[i]=='W')
            cow+=CO;
        i++;
    }
    cout<<cow;
}