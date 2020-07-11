#include <iostream>
#include <string>
#include <vector>
using namespace std;


int main(){
    string a, b;
    cin >>a>>b;
    int cnt_a=0;
    int cnt_b=0;
    for(int i=0; i<a.size(); i++){
        if(a[i]=='1'){
            cnt_a++;
        }
    }
    for(int i=0; i<b.size(); i++){
        if(b[i]=='1'){
            cnt_b++;
        }
    }

    if(cnt_a%2==1){
        cnt_a+=1;
    }

    if(cnt_b<=cnt_a){
        cout<<"VICTORY";
    }
    else{
        cout<<"DEFEAT";
    }
}