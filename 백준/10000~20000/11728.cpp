#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int arr1[1000001];
int arr2[1000001];

int main(){
    ios::sync_with_stdio(false);
    int n,m;
    cin >>n>>m;
    vector<int> v;
    for(int i = 0; i<n; i++){
        cin >>arr1[i];
    }
    for(int j=0; j<m; j++){
        cin >>arr2[j];
    }
    int i = 0;
    int j = 0;
    while(i<n && j<m){
        if(arr1[i]<arr2[j]){
            v.push_back(arr1[i]);
            i++;
        }
        else{
            v.push_back(arr2[j]);
            j++;
        }
    }
    while(i<n){
        v.push_back(arr1[i]);
        i++;
    }
    while(j<m){
        v.push_back(arr2[j]);
        j++;
    }
    for(int k = 0; k < v.size(); k++){
        cout<<v[k]<<" ";
    }
}