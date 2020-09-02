#include <string>
#include <vector>
#include <iostream>
using namespace std;
int x[] = {0,0,1,1};
int y[] = {0,1,0,1};
char arr[31][31];
bool visited[31][31];
int max_n, max_m;
bool check(int a, int b){
    if(0<=a && a<max_m && 0<=b && b<max_n){
        return true;
    }
    return false;
}

int erase(int a, int b){
    bool same=true;
    int total = 0;
    for(int i=0; i<4; i++){
        int nx=a+x[i];
        int ny=b+y[i];
        if(!check(nx,ny) || arr[a][b]!=arr[nx][ny] || arr[nx][ny]=='X'){
            same=false;
            break;
        }
    }
    if(same){
        for(int i=0; i<4; i++){
            int nx=a+x[i];
            int ny=b+y[i];
            if(!visited[nx][ny]){
                visited[nx][ny]=true;
                total++;
            }
        }
        return total;
    }
    else{
        return 0;
    }
}

void down(){
    for(int i=0; i<max_m; i++){
        for(int j=0; j<max_n; j++){
            if(visited[i][j]==true){
                arr[i][j]='X';
            }
        }
    }
    for(int j=0; j<max_n; j++){
        for(int i=max_m-1; i>=0; i--){
            if(arr[i][j]=='X'){
                for(int k=i-1; k>=0; k--){
                    if(arr[k][j]!='X'){
                        arr[i][j]=arr[k][j];
                        arr[k][j]='X';
                        break;
                    }
                }
            }
        }
    }
}



int solution(int m, int n, vector<string> board) {
    int answer = 0;
    max_m = m;
    max_n = n;
    for(int i=0; i<board.size(); i++){
        for(int j=0; j<board[i].size(); j++){
            arr[i][j]=board[i][j];
        }
    }
    
    while(1){
        int sum=0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                visited[i][j]=false;
            }
        }
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(arr[i][j]!='X'){
                    sum+=erase(i,j);
                }
            }
        }
        down();
        if(sum==0){
            break;
        }
        answer+=sum;
    }
    
    return answer;
}