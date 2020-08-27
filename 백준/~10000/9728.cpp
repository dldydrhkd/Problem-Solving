#include <iostream>
#include <string>
using namespace std;

int main(){
    int n;
    cin >>n;
    string str;
    cin >>str;

    int cnt_max = 0;
    int l = 1;
    for(int k = 0; k < n-1; k++){
        if(str[k]==str[k+1] || str[k+1]=='V'){
            if(cnt_max<l)
                cnt_max = l;
            l = 0;
        }
        if(str[k]=='V'){
            if(cnt_max<l){
                cnt_max = l;
            }
            l = 0;
        }
        l++;
    }
    if(cnt_max<l){
        cnt_max = l;
    }
    cout<<cnt_max;
}