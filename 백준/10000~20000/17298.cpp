#include <iostream>
#include <stack>
using namespace std;
int arr[1000001];

int main(){
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    stack<int> st;
    stack<int> answer;
    for(int i=n-1; i>=0; i--){
        while(!st.empty()){
            if(st.top()>arr[i]){
                answer.push(st.top());
                break;
            }
            else{
                st.pop();
            }
        }
        if(st.empty()){
            answer.push(-1);
        }
        st.push(arr[i]);
    }
    while(!answer.empty()){
        cout<<answer.top()<<" ";
        answer.pop();
    }
}