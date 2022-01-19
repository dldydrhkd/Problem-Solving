#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int arr[1000001];

int main(){
    int n;
    cin >>n;
    for(int i=0; i<n; i++){
        cin >>arr[i];
    }
    vector<int> v;
    v.push_back(arr[0]);
    vector<int>::iterator low;
    for(int i=1; i<n; i++){
        low = lower_bound(v.begin(), v.end(), arr[i]);
        if(low == v.end()){
            v.push_back(arr[i]);
        }
        else{
            v[low-v.begin()]=arr[i];
        }
    }
    cout<<v.size()<<"\n";
}
