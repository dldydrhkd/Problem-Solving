#include <iostream>
#include <string>
using namespace std;

int main(){
   int a;
   cin >> a;
   string str;
   cin >> str;
   int cnt = 0;
   int count_a = 0;
   int count_b = 0;
   for(int i=0; i<str.size();){
      for(int j=0; j<2; j++){
         if(str[i + j] == 'a')
            count_a++;
         if(str[i + j] == 'b')
            count_b++;
      }
      for(int j=0; j<2; j++){
         if((count_a > count_b) && str[i] == 'a'){
            count_a--;
            count_b++;
            str[i] = 'b';
            cnt++;
            continue;
         }
         if((count_b > count_a) && str[i] == 'b'){
            count_a++;
            count_b--;
            str[i] = 'a';
            cnt++;
            continue;
         }
      }
      i+=2;
   }
   cout<<cnt<<"\n";
   cout<<str;
}