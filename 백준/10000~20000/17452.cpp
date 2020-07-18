#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
string arr[100001];

int main(){
   int n;
   cin >>n;
   for(int i=0; i<n; i++){
      cin >>arr[i];
   }
   int mini=987654321;
   for(int i=0; i<26; i++){
      vector<pair<int,int>> front;
      vector<pair<int,int>> back;
      for(int j=0; j<n; j++){
         for(int k=0; k<arr[j].size(); k++){
            if(i==arr[j][k]-'a'){
               int temp_front=k;
               int temp_back=arr[j].size()-1-k;
               front.push_back({temp_front,j});
               back.push_back({temp_back,j});
            }
         }
      }
      sort(front.begin(), front.end());
      sort(back.begin(), back.end());
      if(front.size()==0){
         continue;
      }
      int j=0;
      int k=0;
      bool check=false;
      while(front[j].second==back[k].second){
         if(j+1>front.size()-1 && k+1>back.size()-1){
            check=true;
            break;
         }
         else if(j+1>front.size()-1){
            k++;
         }
         else if(k+1>back.size()-1){
            j++;
         }
         else{
            if(front[j+1].first>back[k+1].first){
               k++;
            }
            else{
               j++;
            }
         }
      }
      if(check){
         continue;
      }
      mini=min(mini,front[j].first+back[k].first);
   }

   if(mini==987654321){
      cout<<"-1\n";
   }
   else{
      cout<<mini;
   }

}