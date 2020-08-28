#include <iostream>
#include <string>
using namespace std;
int arr[200001][26];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    string str;
    cin >> str;
    int n;
    cin >>n;
    for(int i=0; i<str.size(); i++){
        for(int j=0; j<26; j++){
            if(str[i]-'a' == j){
                arr[i+1][j] += arr[i][j]+1;
            }
            else{
                arr[i+1][j] += arr[i][j];
            }
        }
    }
    cout<<arr[11][0];
    while(n--){
        char c;
        int s,e;
        cin >>c>>s>>e;
        int temp = c-'a';
        int sum = arr[e+1][temp] - arr[s][temp];
        cout<<sum<<"\n";
    }
}