#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int arr[1000010];

int main(){
    int n,k;
    cin >>n>>k;
    vector<int> lion;
    for(int i=0; i<n; i++){
        cin>>arr[i];
        if(arr[i]==1){
            lion.push_back(i);
        }
    }
    int answer = 987654321;
    for(int i=0; i<lion.size(); i++){
        if(i+k-1<lion.size()){
            answer=min(answer, lion[i+k-1]-lion[i]+1);
        }
    }
    if(answer==987654321){
        cout<<"-1";
    }
    else{
        cout<<answer;
    }
}