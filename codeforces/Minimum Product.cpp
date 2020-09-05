#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

int main(){
   int t;
   cin >>t;
   while(t--){
      ll a,b,x,y,n;
      cin >>a>>b>>x>>y>>n;
      ll answer = a*b;
      if(a-x <= n){
         if(b-y >= n-a+x){
            ll temp = x*(b-(n-a+x));
            answer=min(answer,temp);
         }
         else{
            ll temp = x*y;
            answer = min(answer, temp);
         }
      }
      else{
         ll temp=(a-n)*b;
         answer = min(answer,temp);
      }
      if(b-y <= n){
         if(a-x >= n-b+y){
            ll temp = y*(a-(n-b+y));
            answer = min(answer,temp);
         }
         else{
            ll temp = x*y;
            answer = min(answer,temp);
         }
      }
      else{
         ll temp = a*(b-n);
         answer = min(answer,temp);
      }
      cout<<answer<<"\n";
   }
}