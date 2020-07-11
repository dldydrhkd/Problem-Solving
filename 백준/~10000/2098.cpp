#include <iostream>
#include <algorithm>
using namespace std;
int w[16][16];
int ans[(1<<16)][16];

int main(){
    int n;
    cin >>n;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >>w[i][j];
        }
    }
    for(int i=0; i<(1<<n); i++){
        for(int j=0; j<n; j++){
            ans[i][j]=1000000000;
        }
    }

    ans[1][0]=0;
    for(int i=0; i<(1<<n); i++){
        for(int j=1; j<n; j++){
            if(i&(1<<j)){
                for(int k=0; k<n; k++){
                    if(w[k][j] && (i&(1<<k)) && k!=j ){
                        ans[i][j]=min(ans[i][j],ans[i-(1<<j)][k]+w[k][j]);
                    }
                }
            }
        }
    }
    int sum= 1000000000;
    int a=(1<<n)-1;
    for(int i=0; i<n; i++){
        if(w[i][0]){
            sum=min(ans[a][i]+w[i][0],sum);
        }
    }

    cout<<sum;
}