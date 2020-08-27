#include <iostream>
#include <math.h>
using namespace std;
long long arr[100001];

int main(){
    int n;
    cin >>n;
    for(int i=0; i<n; i++){
        cin >>arr[i];
    }
    int i=0;
    int j=n-1;
    long long answer = arr[i]+arr[j];
    while(i<j){
        if(abs(answer) > abs(arr[i]+arr[j])){
            answer = arr[i]+arr[j];
        }
        if(arr[i]+arr[j]==0){
            answer=0;
            break;
        }
        else if(arr[i]+arr[j]>0){
            j--;
        }
        else if(arr[i]+arr[j] < 0){
            i++;
        }
    }
    cout<<answer;
}