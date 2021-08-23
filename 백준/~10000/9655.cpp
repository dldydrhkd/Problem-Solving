#include <iostream>
using namespace std;
bool dp[1001];

int main(){
    int n;
    cin >> n;

    dp[1] = true;
    dp[2] = false;
    dp[3] = true;
    
    for(int i=4; i<=1000; i++){
        if(dp[i-1]==false || dp[i-3]==false){
            dp[i]=true;
        }
        else{
            dp[i]=false;
        }
    }
    if(dp[n]==true){
        cout<<"SK";
    }
    else{
        cout<<"CY";
    }
}

/*
상근이와 창영이가 게임을 하는데 시작이 정해져있다.
상근이가 1을 가져가거나 3을 가져가거나 둘중 하나이기 때문에
n-1과 n-3의 결과만 보면 된다
상근이가 먼저 가져갈 수 있으므로 n-1과 n-3중 둘 중 하나만 창영이가 turn이였다면 dp[n]에 상근이가 가져갈 수 있다
*/
