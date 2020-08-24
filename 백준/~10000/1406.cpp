#include <iostream>
#include <string>
#include <list>
using namespace std;
list<char> l;

int main(){
   ios::sync_with_stdio(false);
   string str;
   cin >>str;
   for(int i = 0; i<str.size(); i++){
      l.push_back(str[i]);
   }
   int n;
   cin >> n;
   list<char>::iterator it = l.end();
   while(n--){
      char c;
      cin >> c;
      if(c == 'P'){
         char input;
         cin >> input;
         l.insert(it,input);
      }
      if(c == 'L'){
         if(it == l.begin())
            continue;
         it--;
      }
      if(c == 'D'){
         if(it == l.end())
            continue;
         it++;
      }
      if(c == 'B'){
         if(it == l.begin())
            continue;
         if(l.size() == 0)
            continue;
         it=l.erase(--it);
      }
   }
   for(it=l.begin(); it!=l.end(); it++){
      cout<<*it;
   }
}