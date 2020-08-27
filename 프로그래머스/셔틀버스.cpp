#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

string  itoa(int a){
    string str = "";
    str += a/60/10 + '0';
    str += a/60%10 + '0';
    str += ":";
    str += a%60/10 + '0';
    str += a%60%10 + '0';
    return str;
}

struct bus{
    int go;
    vector<int> crew_time;
};

string solution(int n, int t, int m, vector<string> timetable) {
    string answer;
    int crew_num = timetable.size();
    vector<int> time;
    for(int i = 0; i<timetable.size(); i++){
        int h = (timetable[i][0]-'0')*10 + timetable[i][1]-'0';
        int m = (timetable[i][3]-'0')*10 + timetable[i][4]-'0';
        time.push_back(h*60 + m);
    }
    sort(time.begin(), time.end());
    vector<bus> v(n+1);
    for(int i = 1; i <= n; i++){
        v[i-1].go = (i-1)*t + 9*60;
    }
    int index = 0;
    int i = 0;
    while(i < time.size() && index < n){
        if(v[index].go >= time[i] && v[index].crew_time.size() != m){
            v[index].crew_time.push_back(time[i]);
            i++;
        }
        else{
            index++;
        }
    }
    for(i = n-1; i >= 0; i--){
        if(v[i].crew_time.size() < m)
        {
            answer = itoa(v[i].go);
            return answer;
        }
        else{
            for(int j=m-1; j>0; j--){
                if(v[i].crew_time[j]!=v[i].crew_time[j-1]){
                    answer = itoa(v[i].crew_time[j]-1);
                    return answer;
                }
            }
            if(i != 0 && v[i].crew_time[0]-1 != v[i-1].go){
                answer = itoa(v[i].crew_time[0]-1);
                return answer;
            }
        }
    }
    answer = itoa(v[0].crew_time[m-1]-1);
    return answer;
}