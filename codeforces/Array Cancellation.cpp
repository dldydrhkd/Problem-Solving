#include <iostream>
#include <stack>
#include <math.h>
using namespace std;
typedef long long ll;
ll arr[100001];

int main(){
   int t;
   cin >>t;
   while(t--){
      ll n;
      cin >>n;
      ll sum=0;
      for(int i=0; i<n; i++){
         ll temp;
         cin >>temp;
         sum+=temp;
         if(sum<0){
            sum=0;
         }
      }
      cout<<sum<<"\n";
   }
}