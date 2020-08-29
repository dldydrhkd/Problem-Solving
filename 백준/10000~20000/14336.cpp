#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n,q;
long long arr[1001];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >>t;
    int a=1;
    while(a<=t){
        cin >>n>>q;
        for(int i=1; i<=n; i++){
            cin >>arr[i];
            arr[i]+=arr[i-1];
        }
        vector<long long> v;
        v.push_back(0);
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n-i+1; j++){
                v.push_back(arr[j+i-1]-arr[j-1]);
            }
        }
        sort(v.begin(), v.end());
        for(int i=1; i<v.size(); i++){
            v[i] += v[i-1];
        }
        cout<<"Case #"<<a<<":\n";
        while(q--){
            int a,b;
            cin >>a>>b;
            cout<<v[b]-v[a-1]<<"\n";
        }
        a++;
    }
}