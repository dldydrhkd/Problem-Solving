#include <iostream>
#include <string>
using namespace std;
int arr[10];
int n;
int sum[11];
char cal[10][10];


bool check(int idx){
   int a = idx;
   for(int i=1; i<=10; i++){
      sum[i]=sum[i-1]+arr[i-1];
   }
   for(int i=0; i<=idx; i++){
      for(int j=0; j<=a; j++){
         if(cal[i][j]=='-' && sum[i+1+j]-sum[i]<0){
            continue;
         }
         else if(cal[i][j]=='+' && sum[i+1+j]-sum[i]>0){
            continue;
         }
         if(cal[i][j]=='0' && sum[i+1+j]-sum[i]==0){
            continue;
         }
         return false;
      }
      a--;
   }
   return true;
}

void func(int idx){
   if(idx==n){
      for(int i=0; i<n; i++){
         cout<<arr[i]<<" ";
      }
      exit(0);
   }
   for(int i=-10; i<=10; i++){
      arr[idx]=i;
      if(check(idx)){
         func(idx+1);
      }
   }
}

int main(){
   cin >> n;
   string str;
   cin >>str;
   int a = n;
   int k = 0;
   for(int i=0; i<n; i++){
      for(int j=0; j<a; j++){
         cal[i][j]=str[k];
         k++;
      }
      a--;
   }
   for(int i=-10; i<=10; i++){
      arr[0]=i;
      if(check(0)){
         func(1);
      }
   }
}