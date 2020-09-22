#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 100000+2
int arr1[2222222];
int arr2[2222222];

int find_min(int a, int b, int nodeNum, int L, int R){
    if(b < L || R < a) return 1000000000;
    if(a <= L && R <= b) return arr1[nodeNum];
    int mid = (L+R)/2;
    return min(find_min(a,b,nodeNum*2,L,mid),find_min(a,b,nodeNum*2+1,mid+1,R));
}

int find_max(int a, int b, int nodeNum, int L, int R){
    if(b < L || R < a) return 0;
    if(a <= L && R <= b) return arr2[nodeNum];
    int mid = (L+R)/2;
    return max(find_max(a,b,nodeNum*2,L,mid),find_max(a,b,nodeNum*2+1,mid+1,R));
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin >>n>>m;
    int size=1;
    while(n>size){
        size*=2;
    }
    for(int i=1; i<=n; i++){
        cin>>arr1[i+size-1];
        arr2[i+size-1]=arr1[i+size-1];
    }
    for(int i=size-1; i>=1; i--){
        arr1[i]=min(arr1[i*2],arr1[i*2+1]);
        arr2[i]=max(arr2[i*2],arr2[i*2+1]);
    }

    for(int i=0; i<m; i++){
        int a,b;
        cin >>a>>b;
        cout<<find_min(a,b,1,1,size-1)<<" "<<find_max(a,b,1,1,size-1)<<"\n";
    }
}