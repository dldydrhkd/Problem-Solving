#include <iostream>
#include <stack>
using namespace std;

int main(){
    int n;
    cin >>n;
    while(n--){
        int k;
        cin >>k;
        string str;
        cin >>str;
        stack<char> st;
        bool check = true;
        for(int i=0; i<str.size(); i++){
            if(str[i]=='>') st.push(str[i]);
            else{
                if(!st.empty()){
                    st.pop();
                }
                else{
                    check = false;
                    break;
                }
            }
        }
        if(!st.empty()) check =false;
        if(check){
            cout<<"legal\n";
        }
        else{
            cout<<"illegal\n";
        }
    }
}