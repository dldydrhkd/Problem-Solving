#include <string>
#include <algorithm>
#include <vector>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer="";
    sort(participant.begin(),participant.end());
    sort(completion.begin(),completion.end());
    for(int i=0; i<participant.size()-1; i++){
        if(participant[i]!=completion[i]){
            answer=participant[i];
            return answer;
        }
    }
    int size=participant.size();
    answer=participant[size-1];
    return answer;
}