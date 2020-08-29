#include <iostream>
using namespace std;
int arr[100001][3];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >>n;
    for(int i=1; i<=n; i++){
        char a;
        cin >>a;
        if(a=='H'){
            arr[i][0]=arr[i-1][0]+1;
            arr[i][1]=arr[i-1][1];
            arr[i][2]=arr[i-1][2];
        }
        else if(a=='P'){
            arr[i][0]=arr[i-1][0];
            arr[i][1]=arr[i-1][1]+1;
            arr[i][2]=arr[i-1][2];
        }
        else if(a=='S'){
            arr[i][0]=arr[i-1][0];
            arr[i][1]=arr[i-1][1];
            arr[i][2]=arr[i-1][2]+1;
        }
    }
    int answer=0;
    for(int i=1; i<=n; i++){
        int sum1=0;
        int sum2=0;
        for(int j=0; j<3; j++){
            sum1=max(arr[i][j]-arr[0][j],sum1);
            sum2=max(arr[n][j]-arr[i][j],sum2);
        }
        answer=max(answer,sum1+sum2);
    }
    cout<<answer;
}