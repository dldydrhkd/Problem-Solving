#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;
bool arr[27];

int main(){
    int n;
    cin >>n;
    for(int i=0; i<n; i++){
        char a;
        cin >> a;
        if(a == 'T') arr[i]=true;
    }
    cin.ignore();
    string str;
    getline(cin,str);
    vector<char> v;
    for(int i=0; i<str.size(); i++){
        if(str[i]==' ') continue;
        v.push_back(str[i]);
    }
    stack<bool> st;
    for(int i=0; i<v.size(); i++){
        if(v[i]>= 'A' && v[i]<='Z') st.push(arr[v[i]-'A']);
        else{
            if(v[i]=='*'){
                bool a = st.top();
                st.pop();
                bool b = st.top();
                st.pop();
                st.push(a&b);
            }
            else if(v[i]=='+'){
                bool a = st.top();
                st.pop();
                bool b = st.top();
                st.pop();
                st.push(a|b);
            }
            else if(v[i]=='-'){
                bool a = st.top();
                st.pop();
                st.push(!a);
            }
        }
    }
    if(st.top()==true) cout<<"T";
    else cout<<"F";
}