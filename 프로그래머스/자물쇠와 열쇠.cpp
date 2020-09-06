#include <string>
#include <vector>
#include <iostream>
using namespace std;

bool check(vector<vector<int>> key, vector<vector<int>> lock){
    int n=key.size();
    int m=lock.size();
    int k=2*n+m-2;
    vector<vector<int>> arr(k,vector<int>(k,2));
    int hole=0;
    for(int i=0; i<m; i++){
        for(int j=0; j<m; j++){
            if(lock[i][j]==0) hole++;
            arr[i+n-1][j+n-1]=lock[i][j];
        }
    }
    for(int i=0; i<k-n+1; i++){
        for(int j=0; j<k-n+1; j++){
            int cnt=hole;
            bool correct=true;
            for(int p=0; p<n; p++){
                for(int q=0; q<n; q++){
                    if(arr[i+p][j+q]==2) continue;
                    if(arr[i+p][j+q]==0 && key[p][q]==1) cnt--;
                    if(arr[i+p][j+q]==key[p][q]){
                        correct=false;
                    }
                }
            }
            if(correct && cnt==0) return true;
        }
    }
    return false;
}

vector<vector<int>> rotation(vector<vector<int>> key){
    vector<vector<int>> v(key.size());
    for(int j=0; j<key.size(); j++){
        for(int i=key.size()-1; i>=0; i--){
            v[j].push_back(key[i][j]);
        }
    }
    return v;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer=false;
    answer=check(key,lock);
    vector<vector<int>> v;
    if(!answer){
        v = rotation(key);
        answer = check(v, lock);
    }
    if(!answer){
        v = rotation(v);
        answer = check(v, lock);
    }
    if(!answer){
        v = rotation(v);
        answer = check(v, lock);
    }
    return answer;
}