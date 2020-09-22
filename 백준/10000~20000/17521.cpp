#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
ll answer;
ll n,m;
int arr[15];

void cal(ll coin, ll money, ll index){
    answer=max(answer,money);
    if(index==n){
        return ;
    }
    cal(coin+money/arr[index],money%arr[index],index+1);  //사는경우
    cal(coin,money,index+1);   //안 사는 경우
    if(coin>0){
        cal(0,money+coin*arr[index],index+1);   //파는 경우
    }
}

int main(){
    cin >> n >> m;
    for(int i=0; i<n; i++){
        cin >>arr[i];
    }
    cal(0, m, 0);
    cout<<answer;
}