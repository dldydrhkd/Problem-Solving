#include <iostream>
#include <string>
#include <stack>
using namespace std;
int l,r;


int main(){
    string str;
    cin >>str;
    for(int i=0; i<str.size(); i++){
        if(str[i]=='>'){
            l++;
        }
        if(str[i]=='<'){
            r++;
        }
    }
    if(l!=r){
        cout<<"Keine Loesung";
    }
    else{
        stack<int> st;
        for(int i=0; i<str.size(); i+=2){
            if(st.empty()){
                st.push(str[i]);
                cout<<"[";
            }
            else{
                if(str[i]=='>' && st.top()=='<'){
                    cout<<"]";
                    st.pop();
                }
                else if(str[i]=='<' && st.top()=='>'){
                    cout<<"]";
                    st.pop();
                }
                else{
                    st.push(str[i]);
                    cout<<"[";
                }
            }
        }
    }
}