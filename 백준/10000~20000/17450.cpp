#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
pair<double,double> v[3];
vector<pair<double, int>> ans(3);

int main(){
    for(int i=0; i<3; i++){
        cin >>v[i].first;
        cin >>v[i].second;
    }

    for(int i=0; i<3; i++){
        if(v[i].first*10>=5000){
            ans[i].first=v[i].second*10/(v[i].first*10-500);
        }
        else{
            ans[i].first=v[i].second*10/(v[i].first*10);
        }
        ans[i].second=i;
    }

    sort(ans.begin(), ans.end());

    if(ans[2].second==0){
        cout<<"S";
    }else if(ans[2].second==1){
        cout<<"N";
    }else{
        cout<<"U";
    }

}