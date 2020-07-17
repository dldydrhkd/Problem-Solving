#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
vector<int> prime;
bool visited[1000001];

int main(){
   int k;
   cin >>k;
   for(int i=2; i<=1000000; i++){
      int cnt=1;
      if(visited[i]==true){
         continue;
      }
      while(i*cnt<=1000000){
         if(!visited[i] && cnt==1){
            prime.push_back(i);
            cnt++;
            continue;
         }
         visited[i*cnt]=true;
         cnt++;
      }   
   }
   int cnt=0;
   for(int i=0; i<prime.size(); i++){
      if(k==1){
         break;
      }

      while(k%prime[i]==0 && k!=1){
         k=k/prime[i];
         cnt++;
      }
   }
   double ans=log(cnt)/log(2);
   cout<<ceil(ans);
}