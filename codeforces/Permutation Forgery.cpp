#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int arr[101];

int main(){
   int t;
   cin >>t;
   while(t--){
      int n;
      cin >>n;
      for(int i=0; i<n; i++){
         cin >>arr[i];
      }
      int p=0;
      int q=n-1;
      while(p<q){
         int temp=arr[p];
         arr[p]=arr[q];
         arr[q]=temp;
         p++;
         q--;
      }
      for(int i=0; i<n; i++){
         cout<<arr[i]<<" ";
      }
      cout<<"\n";    
   }
}