#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(){
    string str;
    while(getline(cin,str)){
        if(str.size()==1 && str[0]=='#'){
            break;
        }
        stack<char> st;
        bool check=true;
        for(int i=0; i<str.size(); i++){
            if(str[i] =='(' || str[i] == '{' || str[i] == '['){
                st.push(str[i]);
            }
            else if(str[i] == ')' || str[i] == '}' || str[i] == ']'){
                if(!st.empty()){
                    if(str[i]==')' && st.top()=='(') st.pop();
                    else if(str[i]=='}' && st.top()=='{') st.pop();
                    else if(str[i]==']' && st.top()=='[') st.pop();
                    else{
                        check=false;
                        break;
                    }
                }
                else{
                    check=false;
                    break;
                }
            }
        }
        if(!st.empty()){
            check=false;
        }
        if(check)
            cout<<"Legal\n";
        else
            cout<<"Illegal\n";
    }
}