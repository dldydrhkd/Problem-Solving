#include <iostream>
#include <stack>
using namespace std;
int arr[1000001];
pair<int,int> cnt[1000001];

int main(){
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> cnt[i].first;
        arr[cnt[i].first]++;
    }
    for(int i = 0; i<n; i++){
        cnt[i].second=arr[cnt[i].first];
    }
    stack<pair<int,int>> st;
    stack<int> answer;
    for(int i=n-1; i>=0; i--){
        while(!st.empty()){
            if(st.top().second > cnt[i].second){
                answer.push(st.top().first);
                break;
            }
            else{
                st.pop();
            }
        }
        if(st.empty()){
            answer.push(-1);
        }
        st.push(cnt[i]);
    }
    while(!answer.empty()){
        cout<<answer.top()<<" ";
        answer.pop();
    }
}