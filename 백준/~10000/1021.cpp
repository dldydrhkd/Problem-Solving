#include <iostream>
#include <deque>
using namespace std;
int arr[51];

int main(){
    int n,m;
    cin >> n>>m;
    deque<int> q;
    for(int i=1; i<=n; i++){
        q.push_back(i);
    }
    for(int i=1; i<=m; i++){
        cin>>arr[i];
    }
    int answer=0;
    for(int i=1; i<=m; i++){
        int cnt=0;
        for(int j=0; j<q.size(); j++){
            if(q[j]==arr[i]) break;
            cnt++;
        }
        if(cnt<=q.size()-cnt){
            answer+=cnt;
            while(cnt--){
                q.push_back(q.front());
                q.pop_front();
            }
            q.pop_front();
        }
        else{
            answer+=q.size()-cnt;
            int temp=q.size()-cnt;
            while(temp--){
                q.push_front(q.back());
                q.pop_back();
            }
            q.pop_front();
        }
    }
    cout<<answer;
}