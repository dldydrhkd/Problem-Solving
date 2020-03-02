#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 20
pair<int,int> arr[102];
int n;
pair<int,int> start;
pair<int,int> festival;
int cu[101];
bool visited[102];
vector<int> v[102];


int distance(pair<int,int> a, pair<int,int> b){
    return abs(a.first-b.first)+abs(b.second-a.second);
}

void dfs(int start){
    visited[start]=true;
    for(int i=0; i<v[start].size(); i++){
        int next=v[start][i];
        if(!visited[next]){
            dfs(next);
        }
    }
}




int main(){
     int t;
     cin >>t;
     while(t--){
         for(int i=0; i<=n+1; i++){
             v[i].clear();
             visited[i]=false;
         }
         cin >>n;
         cin >>start.first>>start.second;
         arr[0]=start;
         for(int i=1; i<=n; i++){
             cin >>arr[i].first>>arr[i].second;
         }
         cin >> festival.first>>festival.second;
         arr[n+1]=festival;

         for(int i=0; i<=n+1; i++){
             for(int j=i+1; j<=n+1; j++){
                 if(distance(arr[i],arr[j])<=1000){
                     v[i].push_back(j);
                     v[j].push_back(i);
                 }
             }
         }

         dfs(0);
         
         if(visited[n+1]){
             cout<<"happy\n";
         }
         else{
             cout<<"sad\n";
         }
     }


}

