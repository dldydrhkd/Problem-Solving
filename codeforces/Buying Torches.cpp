#include <iostream>
using namespace std;
typedef unsigned long long ll;

int main(){
   int t;
   cin >>t;
   while(t--){
      ll x,y,k;
      cin >>x>>y>>k;
      ll stick=1;
      ll dest=y*k+k-1;
      ll cnt=k;
      if((dest)%(x-1)!=0){
         cnt++;
      }
      cnt+=(dest)/(x-1);
      cout<<cnt<<"\n";
   }
}