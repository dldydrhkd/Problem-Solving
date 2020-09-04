#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(){
    int n;
    cin >>n;
    stack<int> st;
    stack<char> opt;

    for(int i=0; i<n+1; i++){
        int sum=0;
        if(i==0){
            string str;
            cin >>str;
            for(int j=0; j<str.size(); j++){
                if(str[j]=='.') sum+=1;
                else if(str[j]=='-') sum+=5;
                else if(str[j]==':') sum+=2;
                else sum+=10;
            }
            st.push(sum);
        }
        else{
            char op;
            cin >> op;
            string str;
            cin >> str;
            for(int j=0; j<str.size(); j++){
                if(str[j]=='.') sum+=1;
                else if(str[j]=='-') sum+=5;
                else if(str[j]==':') sum+=2;
                else sum+=10;
            }
            st.push(sum);
            opt.push(op);
        }
    }
    stack<int> st_temp;
    stack<char> opt_temp;
    while(!opt.empty()){
        if(opt.top()=='*'){
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            st.push(a*b);
            opt.pop();
        }
        else{
            opt_temp.push(opt.top());
            st_temp.push(st.top());
            st.pop();
            opt.pop();
        }
    }
    while(!st_temp.empty()){
        st.push(st_temp.top());
        st_temp.pop();
    }
    while(!opt_temp.empty()){
        opt.push(opt_temp.top());
        opt_temp.pop();
    }
    while(!opt.empty()){
        int a=st.top();
        st.pop();
        int b = st.top();
        st.pop();
        st.push(a+b);
        opt.pop();
    }
    cout<<st.top();
}