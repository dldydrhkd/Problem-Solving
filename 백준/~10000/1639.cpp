#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int arr[101];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    string str;
    cin >>str;
    for(int i=0; i<str.size(); i++){
        arr[i+1]+=arr[i]+str[i]-'0';
    }
    int answer =0;
    for(int i=1; i<=str.size()/2; i++){
        for(int j=1; j<=str.size()-i*2+1; j++){
            if(arr[j+i-1]-arr[j-1]==arr[j+i*2-1]-arr[j+i-1]){
                answer = max(answer,i*2);
            }
        }
    }
    cout<<answer;
}