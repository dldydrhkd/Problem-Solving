#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int arr[100001];
stack<int> st;
vector<char> v;

int main(){
   int n;
   cin >> n;
   for(int i=1; i<=n; i++){
      cin >> arr[i];
   }
   int j = 1;
   for(int i = 1; i<=n; i++){
      st.push(i);
      v.push_back('+');
      while(!st.empty() && st.top() == arr[j]){
         v.push_back('-');
         st.pop();
         j++;
      }
   }
   if(!st.empty())
      cout<<"NO\n";
   else{
      for(int i=0; i<v.size(); i++){
         cout<<v[i]<<"\n";
      }
   }
}