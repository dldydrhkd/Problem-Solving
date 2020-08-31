#include <iostream>
#include <string>
using namespace std;
int arr[26];

int main(){
   int t;
   cin >>t;
   while(t--){
      int a;
      cin >>a;
      for(int i=0; i<26; i++){
         arr[i]=0;
      }
      for(int i=0; i<a; i++){
         string str;
         cin >>str;
         
         for(int j=0; j<str.size(); j++){
            arr[str[j]-'a']++;
         } 
      }
      bool check=true;
      for(int j=0; j<26; j++){
         if(arr[j]%a!=0){
            check=false;
            break;
         }
      }
      if(check){
         cout<<"YES\n";
      }
      else{
         cout<<"NO\n";
      }
   }
}