#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(){
    while(1){
        string str;
        getline(cin,str);
        if(str[0]=='.') break;
        stack<char> st;
        bool check = true;
        for(int i=0; i<str.size(); i++){
            if(str[i]=='(' || str[i]=='[') st.push(str[i]);
            else if(str[i]==')' || str[i]==']'){
                if(st.empty()){
                    check=false;
                    break;
                }
                else{
                    if(str[i]==')'){
                        if(st.top()=='(') st.pop();
                        else{
                            check=false;
                            break;
                        }
                    }
                    else if(str[i]==']'){
                        if(st.top()=='[') st.pop();
                        else{
                            check = false;
                            break;
                        }
                    }
                }
            }
        }
        if(!st.empty()){
            check = false;
        }
        if(check){
            cout<<"yes\n";
        }
        else{
            cout<<"no\n";
        }
    }
}