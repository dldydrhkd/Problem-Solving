#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

char arr[21][21];
int x[] = {0,0,-1,1};
int y[] = {1,-1,0,0};
int R,C;
int answer;
bool visited[21][21];
bool alpha[26];

bool check(int a, int b){
    if(a>=0 && a<R && b>=0 && b<C){
        return true;
    }
    return false;
}

bool check_alpha(char a){
    if(alpha[a-'A']){
        return true;
    }
    return false;
}

void move(int a, int b, int num){
    for(int i=0; i<4; i++){
        int next_a = a+x[i];
        int next_b = b+y[i];
        if(check(next_a,next_b) && !visited[next_a][next_b] && !check_alpha(arr[next_a][next_b])){
            visited[next_a][next_b]=true;
            alpha[arr[next_a][next_b]-'A'] = true;
            move(next_a,next_b,num+1);
            visited[next_a][next_b]=false;
            alpha[arr[next_a][next_b]-'A'] = false;
        }
    }
    answer = max(answer,num);
}

int main(){
    cin>>R>>C;
    for(int i=0; i<R; i++){
        string str;
        cin >>str;
        for(int j=0; j<C; j++){
            arr[i][j] = str[j];
        }
    }
    
    visited[0][0]=true;
    alpha[arr[0][0]-'A']=true;
    move(0,0,1);
    cout<<answer<<"\n";

}