#include <iostream>
#include <string>
#include <math.h>
using namespace std;
int n;

void func(long long a){
   long long arr[101];
   for(int i = 0; i<101; i++){
      arr[i]= 0;
   }
   long long i = 0;
   while(a > 0){
      arr[i] = a%2;
      a/=2;
      i++;
   }
   for(i = n-1; i>=0; i--){
      cout<<arr[i];
   }
}

bool check(long long a, long long b){
   long long temp = n;
   while(temp--){
      if(a%2 == b %2){
         return true;
      }
      a/=2;
      b/=2;
   }
   return false;
}

int main(){
   int t;
   cin >>t;
   while(t--){
      cin >>n;
      string str;
      cin >>str;
      long long ans = 0;
      long long temp = 0;
      long long i;
      while(1){
         bool check_ = true;
         for(i = 0; i<n; i++){
            long long temp = 0;
            for(int j = i; j<i+n; j++){
               temp += (str[j]-'0') * pow(2, i+n-1-j);
            }
            if(!check(ans, temp))
            {
               check_=false;
               break;
            }
         }
         if(check_)
            break;
         ans++;
      }
      func(ans);
      cout<<"\n";
   }
}