#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
ll arr[300001];

int main(){
   int n;
   cin >>n;

   for(int i=0; i<n; i++){
      cin >>arr[i];
   }
   ll start=arr[n-1];
   for(int i=n-2; i>=0; i--){
      if(start<arr[i]){
         start=arr[i];
      }
      else if(start>arr[i]){
         if(start%arr[i]!=0){
            ll temp=start/arr[i];
            start=arr[i]*(temp+1);
         }
      }
   }

   cout<<start<<"\n";

}