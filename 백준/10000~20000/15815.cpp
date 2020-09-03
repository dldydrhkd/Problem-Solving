#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(){
    string str;
    cin >>str;
    stack<int> st;
    for(int i=0; i<str.size(); i++){
        if(str[i]>='0' && str[i]<='9'){
            st.push(str[i]-'0');
        }
        else{
            if(str[i]=='+'){
                int a=st.top();
                st.pop();
                int b =st.top();
                st.pop();
                st.push(a+b);
            }
            else if(str[i]=='-'){
                int a=st.top();
                st.pop();
                int b =st.top();
                st.pop();
                st.push(b-a);
            }
            else if(str[i]=='*'){
                int a=st.top();
                st.pop();
                int b =st.top();
                st.pop();
                st.push(a*b);
            }
            else if(str[i]=='/'){
                int a=st.top();
                st.pop();
                int b =st.top();
                st.pop();
                st.push(b/a);
            }
        }
    }
    cout<<st.top();
}