#include <iostream>
#include <algorithm>
using namespace std;
int arr[10010];

int main(){
    int t;
    cin >>t;
    int k = 0;
    while(k<t){
        int n,x;
        cin >>n>>x;
        for(int i=0; i<n; i++){
            cin >>arr[i];
        }
        sort(arr, arr+n);
        int i = 0;
        int j = n-1;
        int cnt = 0;
        while(i<j){
            if(arr[i]+arr[j]>x){
                j--;
            }
            else{
                i++;
                j--;
                cnt++;
            }
        }
        cnt += n - cnt*2;
        k++;
        cout<<"Case #"<<k<<": "<<cnt<<"\n";
    }
}
