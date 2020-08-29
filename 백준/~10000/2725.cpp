#include <iostream>
#include <set>
using namespace std;
int arr[1010];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    set<double> s;
    arr[1]=3;
    for(int i=2; i<=1000; i++){
        int sum=0;
        for(int j=1; j<=i-1; j++){
            s.insert((double)i/j);
        }
        arr[i]=s.size()*2+3;
    }
    int c;
    cin >>c;
    while(c--){
        int n;
        cin >>n;
        cout<<arr[n]<<"\n";
    }
}