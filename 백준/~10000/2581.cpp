#include <iostream>
#include <vector>
using namespace std;
int arr[10001];

int m,n;

int main(){
        vector<int> prime;
        cin >>m>>n;
        for(int i=2; i<=100; i++){
                int cnt=2;
                while(i*cnt<=10000){
                        arr[i*cnt]=1;
                        cnt++;
                }
        }
        for(int i=m; i<=n; i++){
                if(i==1){
                        continue;
                }
                if(!arr[i]){
                        prime.push_back(i);
                }
        }

        long long sum=0;

        for(int i=0; i<prime.size(); i++){
                sum+=prime[i];
        }

        if(sum){
                cout<<sum<<"\n";
                cout<<prime[0];
        }

        else{
                cout<<"-1";
        }

}