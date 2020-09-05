#include <iostream>
using namespace std;
int arr[10];
bool visited[10];
int n,m;

void cal(int index){
    if(index==m){
        for(int i=0; i<m; i++){
            cout<<arr[i]<<" ";
        }
        cout<<"\n";
        return;
    }
    for(int i=1; i<=n; i++){
        if(!visited[i]){
            arr[index]=i;
            visited[i]=true;
            cal(index+1);
            arr[index+1]=0;
            visited[i]=false;
        }
    }
}

int main(){
    cin >>n>>m;
    cal(0);
}