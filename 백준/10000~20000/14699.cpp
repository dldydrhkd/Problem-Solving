#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int height[5001];
int visited[5001];
vector<pair<int,int>> arr;
vector<int> v[5001];

void bfs(int x){
   for(int i=0; i<v[x].size(); i++){
      int temp=v[x][i];
      visited[temp]=max(visited[temp],visited[x]+1);
   }
}

int main(){
   int n,m;
   cin >>n>>m;
   for(int i=1; i<=n; i++){
      int a;
      cin >>a;
      height[i]=a;
      arr.push_back({a,i});
   }
   sort(arr.begin(), arr.end());
   for(int i=0; i<m; i++){
      int a,b;
      cin >>a>>b;
      if(height[a]<height[b]){
         v[b].push_back(a);
      }
      else if(height[b]<height[a]){
         v[a].push_back(b);
      }
   }
   
   for(int i=arr.size()-1; i>=0; i--){
      bfs(arr[i].second);
   }

   for(int i=1; i<=n; i++){
      cout<<visited[i]+1<<"\n";
   }

}