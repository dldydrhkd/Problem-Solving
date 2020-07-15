#include <iostream>
#include <algorithm>
using namespace std;
pair<int,int> arr[6];

int straight(pair<int,int> a, pair<int,int> b, pair<int,int> c){
    int row=a.first+b.first+c.first;
    int col=max(a.second,b.second);
    col=max(col,c.second);
    return row*col;
}

int two(pair<int,int> a, pair<int,int> b, pair<int,int> c){
    int row=max(a.first, b.first+c.first);
    int col=a.second+max(b.second,c.second);
    return row*col;
}
int main(){
    int t;
    cin >>t;
    while(t--){
        for(int i=0; i<3; i++){
            int a,b;
            cin >>a>>b;
            arr[i]={a,b};
            arr[i+3]={b,a};
        }
        int ans=987654321;
        for(int i=0; i<6; i++){
            for(int j=0; j<6; j++){
                for(int k=0; k<6; k++){
                    if(i%3==j%3 || j%3==k%3 || i%3==k%3)continue;
                    ans=min(straight(arr[i],arr[j],arr[k]), ans);
                    ans=min(two(arr[i],arr[j],arr[k]),ans);
                }
            }
        }
        cout<<ans<<"\n";
    }
}