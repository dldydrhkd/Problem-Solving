#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
int arr[10010];
int l,k,c;

bool isPossible(int mid){
    int dist=0;
    int cnt=0;
    for(int i=k; i>=0; i--){
        dist+=arr[i+1]-arr[i];
        if(dist>mid){
            cnt++;
            dist=arr[i+1]-arr[i];
            if(dist>mid){
                cnt=c+1;
                break;
            }
        }
    }
    return cnt<=c;
}

int main(){
    cin>>l>>k>>c;
    for(int i=0; i<k; i++){
        cin >>arr[i];
    }
    arr[k]=0;
    arr[k+1]=l;
    sort(arr,arr+1+k);
    int left,right;
    left=0;
    right=l;
    int mid;
    int answer=2e9;
    while(left<=right){
        mid=(left+right)/2;
        if(isPossible(mid)){
            answer=min(answer,mid);
            right=mid-1;
        }
        else left=mid+1;
    }
    int dist=0;
    int pos=2e9;
    int cnt=0;
    for(int i=k; i>=0; i--){
        dist+=arr[i+1]-arr[i];
        if(dist>answer){
            dist=arr[i+1]-arr[i];
            cnt++;
            pos=min(arr[i+1],pos);
        }
    }
    if(cnt<c) pos=arr[1];
    cout<<answer<<" "<<pos<<"\n";
}