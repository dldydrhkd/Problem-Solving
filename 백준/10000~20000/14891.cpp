#include <iostream>
#include <deque>
using namespace std;
deque<int> v[5];
bool visited[5];

bool check(int i){
    if(i>=1 && i<=4){
        return true;
    }
    return false;
}

void turn(int a,int b){
    if(a<1 || a>4 || visited[a]){
        return;
    }
    visited[a]=true;
    if(check(a+1) && v[a][2]!=v[a+1][6]){
        turn(a+1,-b);
    }
    if(check(a-1) && v[a][6]!=v[a-1][2]){
        turn(a-1,-b);
    }
    if(b==1){
        int temp=v[a].back();
        v[a].push_front(temp);
        v[a].pop_back();
    }
    else{
        int temp=v[a].front();
        v[a].push_back(temp);
        v[a].pop_front();
    }
}

int main(){
    for(int i=1; i<=4; i++){
        string str;
        getline(cin,str);
        for(int j=0; j<str.size(); j++){
            v[i].push_back(str[j]-'0');
        }
    }
    int k;
    cin >>k;
    while(k--){
        for(int i=0; i<5; i++){
            visited[i]=false;
        }
        int a,b;
        cin >>a>>b;
        turn(a,b);
    }
    int sum=0;
    if(v[1][0]==1){
        sum+=1;
    }
    if(v[2][0]==1){
        sum+=2;
    }
    if(v[3][0]==1){
        sum+=4;
    }
    if(v[4][0]==1){
        sum+=8;
    }
    cout<<sum;
}