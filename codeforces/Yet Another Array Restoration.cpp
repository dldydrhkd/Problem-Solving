#include <iostream>
#include <vector>
using namespace std;

int main(){
   int t;
   cin >>t;
   while(t--){
      int n, x, y;
      cin >>n>>x>>y;
      int dif = y-x;
      for(int i=1; i<=dif; i++){
         if(dif%i!=0) continue;
         int temp = n;
         int right=y;
         vector<int> v;
         while(right>=1 && temp){
            v.push_back(right);
            right-=i;
            temp--;
         }
         if(v.back()>x){
            continue;
         }
         right = y+i;
         while(right<=1e9 && temp){
            v.push_back(right);
            right+=i;
            temp--;
         }
         if(temp) continue;
         for(int j=0; j<v.size(); j++){
            cout<<v[j]<<" ";
         }
         cout<<"\n";
         break;
      }
   }
}