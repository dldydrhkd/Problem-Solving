#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    string a,b;
    cin >>a>>b;

    if(a.size()==b.size()){
        int cnt=0;
        for(int i=0; i<a.size(); i++){
            if(a[i]!=b[i]){
                cnt++;
            }
        }
        cout<<cnt;
    }

    else{
        int max=987654321;
        for(int i=0; i<=b.size()-a.size(); i++){
            int cnt=0;
            for(int j=0; j<a.size(); j++){
                if(a[j]!=b[j+i]){
                    cnt++;
                }
            }
            max=min(cnt,max);
        }
        cout<<max;
    }
}