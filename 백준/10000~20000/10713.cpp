#include <iostream>
using namespace std;
long long cost[100001][3];
long long arr[100001];
long long cnt[100001];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin >>n>>m;
    for(int i=1; i<=m; i++){
        cin >>arr[i];
    }
    for(int i=1; i<n; i++){
        cin >>cost[i][0]>>cost[i][1]>>cost[i][2];
    }
    for(int i=1; i<m; i++){
        if(arr[i]<arr[i+1]){
            cnt[arr[i]]++;
            cnt[arr[i+1]]--;
        }
        else if(arr[i]>arr[i+1]){
            cnt[arr[i+1]]++;
            cnt[arr[i]]--;
        }
    }
    for(int i=1; i<n; i++){
        cnt[i]+=cnt[i-1];
    }
    long long sum=0;
    for(int i=1; i<n; i++){
        if(cnt[i]*cost[i][0] > cnt[i]*cost[i][1]+cost[i][2]){
            sum+=cost[i][2]+cost[i][1]*cnt[i];
        }
        else{
            sum+=cost[i][0]*cnt[i];
        }
    }
    cout<<sum;
}