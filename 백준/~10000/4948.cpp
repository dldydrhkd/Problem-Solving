#include <iostream>
using namespace std;
int n;
int arr[1000001];

int main(){
        for(int i=2; i<=1000; i++){
                int cnt=2;
                while(cnt*i<=123456*2){
                        arr[cnt*i]=1;
                        cnt++;
                }
        }
        arr[1]=1;
        while(1){
                cin >>n;
                if(n==0){
                        break;
                }
                int ans=0;
                for(int i=n+1; i<=2*n; i++){
                        if(!arr[i]){
                                ans++;
                        }
                }
                cout<<ans<<"\n";

        }
}