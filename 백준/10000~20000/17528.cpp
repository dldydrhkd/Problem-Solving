#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int dp[252][250*250+1];
pair<int,int> arr[252];

int main(){
    int n;
    cin >>n;
    for(int i=0; i<n; i++){
        cin >>arr[i].first;
        cin >>arr[i].second;
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<250*250+1; j++){
            dp[i][j]=987654321;
        }
    }
    dp[0][arr[0].first]=0;
    dp[0][0]=arr[0].second;
    for(int i=1; i<n; i++){
        for(int j=0; j<250*250+1; j++){
            dp[i][j+arr[i].first]=min(dp[i][j+arr[i].first],dp[i-1][j]);
            dp[i][j]=min(dp[i][j],dp[i-1][j]+arr[i].second);
        }
    }
    int answer=987654321;
    for(int i=0; i<250*250+1; i++){
        answer=min(max(i,dp[n-1][i]),answer);
    }
    cout<<answer;
}