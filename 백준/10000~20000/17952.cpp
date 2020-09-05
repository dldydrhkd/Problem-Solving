#include <iostream>
#include <stack>
using namespace std;

int main(){
    int n;
    cin >>n;
    int cnt=0;
    stack<pair<int,int>> st;
    for(int i=0; i<n; i++){
        int a;
        cin >>a;
        if(a==0){
            if(st.empty()) continue;
            st.top().second--;
            if(st.top().second==0){
                cnt+=st.top().first;
                st.pop();
            }
        }
        else{
            int b,c;
            cin >>b>>c;
            st.push({b,c-1});
            if(st.top().second==0){
                cnt+=st.top().first;
                st.pop();
            }
        }
    }
    cout<<cnt;
}