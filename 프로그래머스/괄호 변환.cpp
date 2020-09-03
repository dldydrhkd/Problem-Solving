#include <string>
#include <stack>
#include <vector>
#include <iostream>

using namespace std;

int check(string s)
{
    stack<char> st;
    for(int i=0; i<s.size(); i++){
        if(s[i]=='('){
            st.push(s[i]);
        }
        else{
            if(st.empty()){
                return (0);
            }
            else{
                st.pop();
            }
        }
    }
    if(!st.empty()){
        return 0;
    }
    return 1;
}




string cal(string p)
{
    if(p.size()==0){
        return p;
    }
    string u;
    string v;
    int r=0;
    int l=0;
    for(int i=0; i<p.size(); i++){
        if(p[i]=='('){
            l++;
        }
        else{
            r++;
        }
        if(r==l){
            u=p.substr(0,i+1);
            break;
        }
    }
    v = p.substr(u.size());
    if (check(u))
    {
        return u+=cal(v);
    }
    else
    {
        string temp="(";
        temp += cal(v);
        temp += ")";
        for(int i=1; i<u.size()-1; i++){
            if(u[i]==')')
                temp+='(';
            else{
                temp+=')';
            }
        }
        return temp;
    }
}

string solution(string p)
{
    string answer = "";
    answer = cal(p);
    return answer;
}