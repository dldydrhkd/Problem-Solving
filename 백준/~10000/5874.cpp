#include <iostream>
#include <string>
using namespace std;

int main(){
    string str;
    cin >> str;
    int cnt = 0;
    int answer = 0;
    for(int i=0; i<str.size()-1; i++){
        if(str[i]=='(' && str[i+1]=='(')
            cnt++;
        if(str[i]==')' && str[i+1] == ')')
            answer += cnt;
    }
    cout<<answer;
}