#include <iostream>
#include <string>
using namespace std;
int arr[50001][26];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    string str;
    cin >>str;
    int q;
    cin >>q;
    for(int i=0; i<str.size(); i++){
        for(int j=0; j<26; j++){
            if(str[i]-'a' == j){
                arr[i+1][j] += arr[i][j]+1;
            }
            else{
                arr[i+1][j] = arr[i][j];
            }
        }
    }
    while(q--){
        int a,b,c,d;
        cin >>a>>b>>c>>d;
        bool check = true;
        for(int k=0; k<26; k++){
            if(arr[b][k]-arr[a-1][k] != arr[d][k]-arr[c-1][k]){
                check = false;
                break;
            }
        }
        if(check){
            cout<<"DA"<<"\n";
        }
        else{
            cout<<"NE"<<"\n";
        }
    }
}