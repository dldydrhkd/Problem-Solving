#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin >>n>>m;
    unordered_map<string,int> name;
    unordered_map<int,string> num;
    for(int i=1; i<=n; i++){
        string str;
        cin >>str;
        name.insert({str,i});
        num.insert({i,str});
    }
    for(int i=0; i<m; i++){
        string str;
        cin >>str;
        if(str[0]>= '0' && str[0]<='9'){
            int temp=stoi(str);
            cout<<num[temp]<<"\n";
        }
        else{
            cout<<name[str]<<"\n";
        }
    }
}