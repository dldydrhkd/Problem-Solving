#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n,m;
int visited[501][501];

void floyd(){
    for(int via=1; via<=n; via++){
        for(int from=1; from<=n; from++){
            for(int to=1; to<=n; to++){
                if(from==to){
                    continue;
                }
                if(visited[from][via]==0 || visited[via][to]==0){
                    continue;
                }
                else{
                    if(visited[from][to]==0){
                        visited[from][to]=visited[from][via]+visited[via][to];
                    }
                    else{
                        visited[from][to]=min(visited[from][to],visited[from][via]+visited[via][to]);
                    }
                }
            }
        }
    }
}

int main(){
    cin >>n>>m;
    for(int i=0; i<m; i++){
        int a,b;
        cin >>a>>b;
        visited[a][b]=1;
    }

    floyd();
    int cnt=0;

    for(int i=1; i<=n; i++){
        int sum=0;
        for(int j=1; j<=n; j++){
            if(visited[i][j]){
                sum++;
            }
            else if(visited[j][i]){
                sum++;
            }
        }
        if(sum==n-1){
            cnt++;
        }
    }

    cout<<cnt;

}