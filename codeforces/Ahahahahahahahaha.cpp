#include <iostream>
#include <vector>
using namespace std;

int main(){
   int t;
   cin >>t;
   while(t--){
      int n;
      cin >>n;
      vector<int> arr;
      int cnt=0;
      for(int i=0; i<n; i++){
         int a;
         cin >>a;
         arr.push_back(a);
         if(arr[i]) cnt++;
      }
      vector<int> ans;
      if(cnt<=arr.size()-cnt){
         for(int i=0; i<arr.size()-cnt; i++){
            ans.push_back(0);
         }
      }
      else{
         if(cnt%2==1) cnt--;
         for(int i=0; i<cnt; i++){
            ans.push_back(1);
         }
      }
      cout<<ans.size()<<"\n";
      for(int i=0; i<ans.size(); i++){
         cout<<ans[i]<<" ";
      }
      cout<<"\n";
   }
}
