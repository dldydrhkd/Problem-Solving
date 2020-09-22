#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct pos{
    pair<int, int> left_low;
    pair<int, int> upper_right;
};

bool cmp1(const pos &a, const pos &b){
    if(a.left_low.second==b.left_low.second){
        return a.left_low.first < b.left_low.first;
    }
    return a.left_low.second < b.left_low.second;
}

bool cmp2(const pos &a, const pos &b){
    if(a.left_low.first==b.left_low.first){
        return a.left_low.second < b.left_low.second;
    }
    return a.left_low.first < b.left_low.first;
}

bool under(int a, int b, int c, int d){
    if(d<=a || c>=b) return false;
    return true;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >>n;
        vector<pos> v;
        for(int i=0; i<n; i++){
            int a,b,c,d;
            cin >>a>>b>>c>>d;
            struct pos p1;
            p1.left_low.first=a;
            p1.left_low.second=b;
            p1.upper_right.first=c;
            p1.upper_right.second=d;
            v.push_back(p1);
        }
        while(1){
            bool changed=false;
            sort(v.begin(), v.end(), cmp1);
            for(int i=0; i<n; i++){
                int heighest=0;
                for(int j=0; j<i; j++){
                    int left_x=v[i].left_low.first;
                    int right_x=v[i].upper_right.first;
                    int y = v[i].left_low.second;
                    int temp_left_x=v[j].left_low.first;
                    int temp_right_x=v[j].upper_right.first;
                    int temp_y=v[j].upper_right.second;
                    if(y>=temp_y && under(left_x, right_x, temp_left_x, temp_right_x)){
                        if(heighest<temp_y){
                            heighest=temp_y;
                        }
                    }
                }
                if(v[i].left_low.second-heighest!=0){
                    changed = true;
                }
                v[i].upper_right.second-=v[i].left_low.second-heighest;
                v[i].left_low.second-=v[i].left_low.second-heighest;
            }
            sort(v.begin(), v.end(), cmp2);
            for(int i=0; i<n; i++){
                int heighest=0;
                for(int j=0; j<i; j++){
                    int left_y=v[i].left_low.second;
                    int right_y=v[i].upper_right.second;
                    int x = v[i].left_low.first;
                    int temp_left_y=v[j].left_low.second;
                    int temp_right_y=v[j].upper_right.second;
                    int temp_x=v[j].upper_right.first;
                    if(x>=temp_x && under(left_y, right_y, temp_left_y, temp_right_y)){
                        if(heighest<temp_x){
                            heighest=temp_x;
                        }
                    }
                }
                if(v[i].left_low.first-heighest!=0){
                    changed = true;
                }
                v[i].upper_right.first-=v[i].left_low.first-heighest;
                v[i].left_low.first-=v[i].left_low.first-heighest;
            }
            if(!changed) break;
        }
        int width=0;
        int height=0;
        for(int i=0; i<n; i++){
            width=max(width, v[i].upper_right.first);
            height=max(height,v[i].upper_right.second);
        }
        cout<<width<<" "<<height<<"\n";
    }
}