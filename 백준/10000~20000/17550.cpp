#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
ll arr[1000010];
ll arr2[1000010];

int main(){
    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        int a;
        cin >>a;
        arr[i] = a*a;
        arr[i]+=arr[i-1];
        arr2[i] = a;
        arr2[i] += arr2[i-1];
    }
    long answer=0;
    for(int i=1; i<=n; i++){
        long sum;
        sum = arr[i] * (arr2[n]-arr2[i]);
        answer=max(answer,sum);
    }
    cout<<answer;
}