#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >>t;
    while(t--){
        int n;
        cin >>n;
        vector<int> v;
        for(int i=0; i<n; i++){
            int a;
            cin >> a;
            v.push_back(a);
        }
        sort(v.begin(), v.end());
        int m;
        cin >> m;
        for(int i=0; i<m; i++){
            int a;
            cin >> a;
            int start=0;
            int end=v.size()-1;
            int mid=(start+end)/2;
            bool check=true;
            while(start<=end){
                if(v[mid]==a){
                    cout<<"1\n";
                    check=false;
                    break;
                }
                else if(v[mid]<a){
                    start=mid+1;
                    mid=(start+end)/2;
                }
                else if(v[mid]>a){
                    end=mid-1;
                    mid=(start+end)/2;
                }
            }
            if(check) cout<<"0\n";
        }
    }
}