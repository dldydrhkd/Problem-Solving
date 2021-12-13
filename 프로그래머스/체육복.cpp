#include <string>
#include <vector>

using namespace std;
int have[100];

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    for(int i=0; i<=n; i++){
        have[i]=1;
    }
    for(int i=0; i<lost.size(); i++){
        have[lost[i]]--;
    }
    for(int i=0; i<reserve.size(); i++){
        have[reserve[i]]++;
    }
    for(int i=0; i<=n; i++){
        if(have[i]==0){
            if(have[i-1]==2){
                have[i]++;
                have[i+1]--;
            }
            else if(have[i+1]==2){
                have[i]++;
                have[i+1]--;
            }
        }
    }
    for(int i=1; i<=n; i++){
        if(have[i]!=0){
            answer++;
        }
    }
    return answer;
}
