#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int visited[101];
int answer=987654321;
int n,m;

struct clothes{
    int t;
    int w;
    int value;
};

bool cmp(const clothes s, const clothes &t){
    if(s.value==t.value){
        return s.t<t.t;
    }
    return s.value < t.value;
}

void func(vector<clothes> &v, int cnt, int before, int sum){
    if(cnt==m){
        answer=min(sum,answer);
        return ;
    }
    for(int i=1; i<=v.size(); i++){
        vector<clothes> temp;
        int new_value=0;
        if(i!=v.size()){
            new_value=v[v.size()-1-i].value;
        }
        for(int j=0; j<i; j++){
            temp.push_back(v[v.size()-1-j]);
        }
        int min_temp=200;
        for(int j=0; j<temp.size(); j++){
            min_temp=min(min_temp,temp[j].t);
        }
        int max_value=0;
        for(int j=0; j<temp.size(); j++){
            temp[j].value=30+(temp[j].t-min_temp)*temp[j].w;
            max_value=max(max_value,temp[j].value);
        }
        sort(temp.begin(),temp.end(),cmp);
        func(temp, cnt+1, max_value, sum-before+new_value+max_value);
    }
}

int main(){
    cin >>n>>m;
    int min_t = 200;
    vector<clothes> v;
    for(int i=0; i<n; i++){
        int a,b;
        cin >>a>>b;
        min_t=min(min_t,a);
        if(!visited[a]){
            visited[a]=b;
        }
        else{
            if(visited[a]<b){
                visited[a]=b;
            }
        }
    }
    for(int i=40; i<=100; i++){
        if(visited[i]){
            clothes c;
            c.t=i;
            c.value=0;
            c.w=visited[i];
            v.push_back(c);
        }
    }
    n=v.size();
    for(int i=0; i<n; i++){
        v[i].value=30+(v[i].t-min_t)*v[i].w;
    }
    sort(v.begin(), v.end(), cmp);
    int temp = 0;
    for(int i=0; i<n; i++){
        temp=max(temp,v[i].value);
    }
    if(m==1){
        cout<<temp;
        return 0;
    }
    else{
        func(v,1,temp,temp);
    }
    cout<<answer;
}