#include <iostream>
#include <algorithm>
using namespace std;
int arr[10010];

int main(){
    int n;
    cin >>n;
    for(int i = 0; i<n; i++){
        cin >>arr[i];
    }
    sort(arr, arr+n);
    int min_answer=5;
    for(int i = 0; i<n; i++){
        int k = 1;
        for(int j=1; j<5; j++){
            if(arr[i]+j==arr[i+k]){
                k++;
            }
        }
        min_answer=min(min_answer,5-k);
    }
    cout<<min_answer;
}