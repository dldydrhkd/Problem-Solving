#include <iostream>
#include <string>
using namespace std;
string str;

void rev(int a, int b){
   while(a<=b){
      char temp;
      temp = str[a];
      str[a] = str[b];
      str[b] = temp;
      a++;
      b--;
   }
}


int main(){
   getline(cin,str);
   int j = 0;
   for(int i=0; i<str.size(); i++){
      if(str[i] == ' ' || str[i] == '<'){
         rev(j, i-1);
         j = i + 1;
      }
      if(str[i]=='<'){
         while(str[i]!='>')
            i++;
         j=i+1;
      }
   }
   if(str[str.size()-1]!='>')
      rev(j,str.size()-1);
   cout<<str;
}