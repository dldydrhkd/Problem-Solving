#include <iostream>
using namespace std;

int main(){
    int t;
    cin >>t;
    while(t--){
        int a,b;
        cin >>a>>b;
        int temp;
        if(a>b){
            temp = a;
            a = b;
            b = temp;
        }
        temp = b-a;
        int answer = temp/10;
        if(temp % 10 != 0) answer++;
        cout<<answer<<"\n";
    }
}