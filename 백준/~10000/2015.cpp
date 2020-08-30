#include<iostream>
#include<map>
using namespace std;
map<int, int> mp;
long long r;
int main() {
    int n,k;
    int s=0;
    cin >>n>>k;
    mp[0]++;
    for(int i=0; i<n; i++){
        int num;
        cin>>num;
        s += num;
        r += mp[s-k];
        mp[s]++;
    }
    cout<<r;
}