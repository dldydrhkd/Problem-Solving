#include <iostream>
using namespace std;
int arr[100010];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,k;
    cin>>n>>k;

    for(int i=1; i<=n; i++){
        int a;
        cin >>a;
        arr[i]=a + arr[i-1];
    }
    int answer = -987654321;
    for(int i=1; i<=n-k+1; i++){
        int sum;
        sum = arr[i+k-1] - arr[i-1];
        if(answer < sum){
            answer = sum;
        }
    }
    cout<<answer;
}