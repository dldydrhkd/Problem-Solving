#include <iostream>
#include <queue>
using namespace std;

int main(){
    int t;
    cin >>t;
    while(t--){
        queue<pair<int,int>> q;
        int a,b;
        cin >>a>>b;
        int arr[10]={0,};
        for(int i=0; i<a; i++){
            int import;
            cin >>import;
            q.push({import,i});
            arr[import]++;
        }
        int cnt=0;
        while(!q.empty()){
            int front_imp=q.front().first;
            int front_index=q.front().second;
            bool exist=false;
            for(int i=front_imp+1; i<=9; i++){
                if(arr[i]) exist=true;
            }
            if(exist){
                q.push(q.front());
                q.pop();
            }
            else{
                cnt++;
                arr[front_imp]--;
                if(b==q.front().second){
                    break;
                }
                q.pop();
            }
        }
        cout<<cnt<<"\n";
    }
}