#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main(){
    int t;
    cin >>t;
    while(t--){
        vector<int> arr1;
        arr1.push_back(-1);
        vector<int> arr2;
        arr2.push_back(-1);
        vector<int> arr;
        int n;
        cin >>n;
        for(int i=0; i<n; i++){
            int a;
            cin >>a;
            arr.push_back(a);
        }
        sort(arr.begin(),arr.end());
        int j=0;
        while(j<n){
            if(arr1.back()+1==arr[j]){
                arr1.push_back(arr[j]);
            }
            else if(arr2.back()+1==arr[j]){
                arr2.push_back(arr[j]);
            }
            j++;
        }
        int cnt1=0;
        int cnt2=0;
        if(arr1.size()>=2){
            cnt1=arr1.size()-1;
        }
        if(arr2.size()>=2){
            cnt2=arr2.size()-1;
        }
        cout<<cnt1+cnt2<<"\n";
    }
}