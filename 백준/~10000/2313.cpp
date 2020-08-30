#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int main(){
    int n;
    cin >>n;
    vector<pair<int,int>> v;
    long long answer = 0;
    while(n--){
        int l;
        cin >>l;
        long long global_sum,local_sum;
        global_sum=local_sum=-1e9;
        int L,R,temp_L,temp_R;
        L=R=temp_L=temp_R=0;
        for(int i=1; i<=l; i++){
            int num;
            cin >>num;
            if(local_sum<0){
                local_sum=num;
                temp_L=temp_R=i;
            }
            else{
                if(local_sum) temp_R++;
                else{
                    temp_L=temp_R=i;
                }
                local_sum+=num;
            }
            if(global_sum < local_sum || (global_sum==local_sum && R-L>temp_R-temp_L)){
                global_sum=local_sum;
                R=temp_R;
                L=temp_L;
            }
        }
        answer+=global_sum;
        v.push_back({L,R});
    }
    cout<<answer<<"\n";
    for(int i=0; i<v.size(); i++){
        cout<<v[i].first<<" "<<v[i].second<<"\n";
    }
}