#include <iostream>
#include <algorithm>
using namespace std;
int arr[20001];

int main(){
    int n,s;
    cin >>n>>s;
    for(int i=0; i<n; i++){
        cin >>arr[i];
    }
    sort(arr, arr+n);
    int i=0;
    int j=n-1;
    int answer=0;
    while(i<j){
        if(arr[i]+arr[j]>s){
            j--;
        }
        else if(arr[i]+arr[j]<=s){
            answer+=j-i;
            i++;
        }
    }
    cout<<answer;
}