#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

int arr[100002];

int main(){
   int n;
   cin >>n;
   vector<int> a,b;
   set<int> A,B;
   for(int i=1; i<=n; i++){
      int t;
      cin >>t;
      arr[t]=true;
      if(i>n/2){
         A.insert(t);
      }
      else{
         a.push_back(t);
      }
   }

   for(int i=1; i<=2*n; i++){
      if(arr[i]){
         continue;
      }
      if(b.size()==n/2){
         B.insert(i);
      }
      else{
         b.push_back(i);
      }
   }
   int cnt=0;

   for(int i=0; i<n/2; i++){
      auto pos = B.upper_bound(a[i]);
      if(pos != B.end()){
         B.erase(pos);
         cnt++;
      }
      else{
         B.erase(B.begin());
      }

      auto cpos=A.upper_bound(b[i]);
      if(cpos != A.end()){
         A.erase(cpos);
         cnt++;
      }
      else{
         A.erase(A.begin());
      }
   }

   cout<<cnt;

}
