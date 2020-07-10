#include <iostream>
using namespace std;

int main(){
    int a,b;
    cin >>a>>b;

    a%=30;
    int c= 12*a;
    if(b==c){
        cout<<"O";
    }
    else{
        cout<<"X";
    }
}