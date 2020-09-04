#include <iostream>
#include <stack>
using namespace std;

int main(){
    int k;
    cin >>k;
    stack<int> st;
    for(int i=0; i<k; i++){
        int a;
        cin >>a;
        if(a!=0){
            st.push(a);
        }
        else{
            if(!st.empty()){
                st.pop();
            }
        }
    }
    long long sum=0;
    while(!st.empty()){
        sum+=st.top();
        st.pop();
    }
    cout<<sum;
}