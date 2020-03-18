#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;


int main(){
        int t;
        cin >>t;
        while(t--){
                int a,b;
                cin >>a>>b;
                long long cnt=1;
                while(cnt*cnt<=b-a){
                        cnt++;
                }
                cnt--;
                long long remain=ceil((double)(b-a-(cnt*cnt))/(double)cnt);
                cout<<2*cnt-1+remain<<"\n";
        }
}