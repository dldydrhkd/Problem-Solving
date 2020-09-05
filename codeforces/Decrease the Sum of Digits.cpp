#include <iostream>
#include <string>
#include <math.h>
using namespace std;
typedef unsigned long long ll;

ll cal(string s,int i){
   ll sum=0;
   for(ll j=i; j<s.size(); j++){
      ll p=1;
      ll temp=s.size()-1-j;
      while(temp--){
         p*=10;
      }
      sum+=(ll)(s[j]-'0')*p;
   }
   return sum;
}

ll check(string s){
   ll sum=0;
   for(int i=0; i<s.size(); i++){
      sum+=s[i]-'0';
   }
   return sum;
}

int main(){
   int t;
   cin >>t;
   while(t--){
      ll s;
      string n;
      cin >>n>>s;
      ll i=0;
      ll sum=0;
      while(i<n.size()){
         if(sum+(n[i]-'0')>=s){
            break;
         }
         sum+=n[i]-'0';
         i++;
      }
      if(check(n)<=s){
         cout<<"0\n";
         continue;
      }
      ll digit=n.size()-i;
      ll temp;
      ll p=1;
      while(digit--){
         p*=10;
      }
      temp=p-cal(n,i);
      cout<<temp<<"\n";
   }
}