#include <iostream>
using namespace std;
char arr[101][101];


int main(){
   int n,m;
   cin >>n>>m;

   for(int i=0; i<n; i++){
      for(int j=0; j<m; j++){
         cin >>arr[i][j];
      }
   }

   for(int i=m-1; i>=0; i--){
      for(int j=0; j<n; j++){
         if(arr[j][i]=='.'){
            cout<<char(46);
         }
         if(arr[j][i]=='O'){
            cout<<char(79);
         }
         if(arr[j][i]=='-'){
            cout<<char(124);
         }
         if(arr[j][i]=='|'){
            cout<<char(45);
         }
         if(arr[j][i]=='/'){
            cout<<char(92);
         }
         if(arr[j][i]=='\\'){
            cout<<char(47);
         }
         if(arr[j][i]=='^'){
            cout<<char(60);
         }
         if(arr[j][i]=='<'){
            cout<<char(118);
         }
         if(arr[j][i]=='v'){
            cout<<char(62);
         }
         if(arr[j][i]=='>'){
            cout<<char(94);
         }
      }
      cout<<"\n";
   }

}