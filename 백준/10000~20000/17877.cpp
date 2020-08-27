#include <iostream>
#include <algorithm>
using namespace std;
int arr[200010];

int main(){
    int n,d;
    cin >>n>>d;
    for(int i = 0; i<n; i++){
        cin >>arr[i];
    }
    for(int i=0; i<n; i++){
        arr[i] = arr[i]/d;
    }
    sort(arr,arr+n);
    long long answer=0;
    long long sum=1;
    for(int i=0; i<n-1; i++){
        if(arr[i]==arr[i+1]){
            sum++;
        }
        else{
            answer+=sum*(sum-1)/2;
            sum=1;
        }
    }
    answer+=sum*(sum-1)/2;
    cout<<answer;
}