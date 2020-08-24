#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<pair<int,int>> v;

bool cmp(pair<int,int> a, pair<int,int> b){
   return a.first > b.first;
}

int main(){
   int n;
   cin >>n;
   for(int i = 0; i< n; i++){
      int a;
      cin >> a;
      v.push_back({a,i});
   }
   sort(v.begin(), v.end(), cmp);
   int sum = 0;
   for(int i=0; i<n; i++){
      sum+=i*v[i].first + 1;
   }
   cout<<sum<<"\n";
   for(int i=0; i<n; i++){
      cout<<v[i].second+1<<" ";
   }
}