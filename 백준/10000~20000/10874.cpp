#include <iostream>
using namespace std;

int main(){
   int n;
   cin >>n;
   for(int i=1; i<=n; i++){
      int cnt=0;
      for(int j=1; j<=10; j++){
         int a;
         cin >>a;
         if(a==((j-1)%5+1)){
            cnt++;
         }
      }
      if(cnt==10){
         cout<<i<<"\n";
      }
   }
}