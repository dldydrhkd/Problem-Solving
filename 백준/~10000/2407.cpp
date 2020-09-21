#include <iostream>
using namespace std;
typedef unsigned long long ull;
pair<ull,ull> dp[101][101];
#define MOD 100000000000000000

void print_long(ull num){
    ull arr[17]={0,};
    int i=16;
    while(num>0){
        arr[i]=num%10;
        num/=10;
        i--;
    }
    for(i=0; i<17; i++){
        cout<<arr[i];
    }
}

int main(){
    int n,m;
    cin >>n>>m;
    for(int i=0; i<=100; i++){
        dp[i][0].first=1;
    }
    for(int i=1; i<=100; i++){
        for(int j=1; j<=i; j++){
            dp[i][j].first=dp[i-1][j].first+dp[i-1][j-1].first;
            if(dp[i][j].first>MOD){
                dp[i][j].second += dp[i][j].first/MOD;
                dp[i][j].first = dp[i][j].first%MOD;
            }
            dp[i][j].second+=dp[i-1][j].second+dp[i-1][j-1].second;
        }
    }
    if(dp[n][m].second>0){
        cout<<dp[n][m].second;
        print_long(dp[n][m].first);
    }
    else{
        cout<<dp[n][m].first;
    }
}