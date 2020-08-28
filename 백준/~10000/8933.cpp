#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main(){
    int t;
    cin >>t;
    while(t--){
        int k;
        string str;
        cin >>k>>str;
        unordered_map<long long, int> mp;
        int answer = 0;
        for(int i=0; i<=str.size()-k; i++){
            int sum =0;
            for(int j=0; j<k; j++){
                if(str[i+j]=='A'){
                    sum+=1;
                }
                if(str[i+j]=='G'){
                    sum+=600;
                }
                if(str[i+j]=='C'){
                    sum+=600*600;
                }
                if(str[i+j]=='T'){
                    sum+=600*600*600;
                }
            }
            answer = max(answer, ++mp[sum]);
        }
        cout<<answer<<"\n";
    }
}