#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(int a, int b){
   return a>b;
}

int main(){
   int t;
   cin >> t;
   while(t--){
      int n;
      cin >>n;
      int arr[101]={0,};
      int fixed[101]={0,};
      for(int i=0; i<n; i++){
         cin >>arr[i];
      }
      for(int i=0; i<n; i++){
         cin >>fixed[i];
      }
      vector<int> pos;
      vector<int> nega;
      for(int i=0; i<n; i++){
         if(!fixed[i]){
            if(arr[i]>=0){
               pos.push_back(arr[i]);
            }
            else{
               nega.push_back(arr[i]);
            }
         }
      }
      sort(pos.begin(),pos.end(),cmp);
      sort(nega.begin(),nega.end(),cmp);
      int j=0;
      int k=0;
      for(int i=0; i<n; i++){
         if(!fixed[i]){
            if(j<pos.size()){
               arr[i]=pos[j];
               j++;
            }
            else if(k<nega.size()){
               arr[i]=nega[k];
               k++;
            }
         }
         cout<<arr[i]<<" ";
      }
      cout<<"\n";
   }
}