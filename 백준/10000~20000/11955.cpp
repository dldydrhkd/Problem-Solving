#include <iostream>
using namespace std;
char arr[101][101];
int r,s,k;
bool check(int i,int j){
    if(i+k-1<r && j+k-1<s){
        return true;
    }
    return false;
}
int main(){
    cin >> r >> s >> k;
    for(int i=0; i<r; i++){
        for(int j=0; j<s; j++){
            cin >>arr[i][j];
        }
    }
    int max_cnt=0;
    int max_i=0;
    int max_j=0;
    for(int i=0; i<r; i++){
        for(int j=0; j<s; j++){
            int cnt=0;
            if(check(i,j)){
                for(int p=1; p<k-1; p++){
                    for(int q=1; q<k-1; q++){
                        if(arr[i+p][j+q]=='*')
                            cnt++;
                    }
                }
            }
            if(max_cnt<cnt){
                max_cnt =cnt;
                max_i=i;
                max_j=j;
            }
        }
    }
    arr[max_i][max_j]='+';
    arr[max_i+k-1][max_j]='+';
    arr[max_i+k-1][max_j+k-1]='+';
    arr[max_i][max_j+k-1]='+';
    for(int i=1; i<k-1; i++){
        arr[max_i+i][max_j]='|';
        arr[max_i+i][max_j+k-1]='|';
        arr[max_i][max_j+i]='-';
        arr[max_i+k-1][max_j+i]='-';
    }
    cout<<max_cnt<<"\n";
    for(int i=0; i<r; i++){
        for(int j=0; j<s; j++){
            cout<<arr[i][j];
        }
        cout<<"\n";
    }
}