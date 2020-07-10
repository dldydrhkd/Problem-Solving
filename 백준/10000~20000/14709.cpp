#include <iostream>
using namespace std;
int arr[6][6];

int main(){
    int n;
    cin >>n;
    for(int i=1; i<=n; i++){
        int a,b;
        cin >>a>>b;
        arr[a][b]=1;
        arr[b][a]=1;
    }

    for(int j=1; j<=5; j++){
        if(arr[2][j]==1){
            cout<<"Woof-meow-tweet-squeek\n";
            return 0;
        }
        if(arr[5][j]==1){
            cout<<"Woof-meow-tweet-squeek\n";
            return 0;
        }
    }

    if(arr[1][3] && arr[3][4] && arr[4][1]){
        cout<<"Wa-pa-pa-pa-pa-pa-pow!\n";
    }
    else{
        cout<<"Woof-meow-tweet-squeek\n";
    }
}