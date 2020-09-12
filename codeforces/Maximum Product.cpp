#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;
typedef long long ll;
 
int main(){
   int t;
   cin >>t;
   while(t--){
      int n;
      cin >>n;
      vector<ll> v_pos;
      vector<ll> v_nega;
      for(int i=0; i<n; i++){
         ll a;
         cin >>a;
         if(a>=0){
            v_pos.push_back(a);
         }
         else{
            v_nega.push_back(a);
         }
      }
      sort(v_pos.begin(), v_pos.end());
      sort(v_nega.begin(),v_nega.end());
      ll ans=-1e18;
      int i=v_pos.size()-1;
      int j=v_nega.size()-1;
      if(v_pos.empty()){
         ll temp=1;
         for(int k=0; k<5; k++){
            temp*=v_nega[j-k];
         }
         ans=max(temp,ans);
      }
      else{
         if(v_pos.size()>=5){
            ll temp=1;
            for(int k=0; k<5; k++){
               temp*=v_pos[i-k];
            }
            ans=max(temp,ans);
         }
         if(v_pos.size()>=3 && v_nega.size()>=2){
            ll temp=1;
            temp*=(v_pos[i]*v_pos[i-1]*v_pos[i-2]*v_nega[0]*v_nega[1]);
            ans=max(temp,ans);
         }
         if(v_pos.size()>=1 && v_nega.size()>=4){
            ll temp=v_pos[i];
            for(int k=0; k<4; k++){
               temp*=v_nega[k];
            }
            ans=max(temp,ans);
         }
         if(v_pos.size()>=2 && v_nega.size()>=3){
            ll temp=1;
            temp*=v_pos[0]*v_pos[1]*v_nega[j]*v_nega[j-1]*v_nega[j-2];
            ans=max(temp,ans);
         }
         if(v_pos.size()>=4 && v_nega.size()>=1){
            ll temp=v_nega[j];
            for(int k=0; k<4; k++){
               temp*=v_pos[k];
            }
            ans=max(temp,ans);
         }
      }
      cout<<ans<<"\n";
   }
}