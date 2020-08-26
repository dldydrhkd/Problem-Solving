#include <string>
#include <iostream>
#include <vector>
#include <stdio.h>
#include <math.h>
using namespace std;

struct s_data{
    int start;
    int end;
};

s_data arr[2001];

int solution(vector<string> lines) {
    int answer = 0;
    for(int i=0; i<lines.size(); i++)
    {
        int end=(((lines[i][11]-'0')*10+(lines[i][12]-'0'))*60*60+((lines[i][14]-'0')*10 + (lines[i][15]-'0'))*60+(lines[i][17]-'0')*10+(lines[i][18]-'0'))*1000+(lines[i][20]-'0')*100+(lines[i][21]-'0')*10+(lines[i][22]-'0');
        int check_point = 0;
        int throughput = 0;
        for(int j=24; j<lines[i].size()-1; j++){
            if(lines[i][j] == '.'){
                check_point = j;
                continue;
            }
            if(check_point)
                throughput += (lines[i][j]-'0') * pow(10, 3-(j-check_point));
            else
                throughput += (lines[i][j]-'0')*1000 - 1;
        }
        int start = end - throughput;
        
        arr[i].start = start;
        arr[i].end = end;
    }
    for(int i = 0; i<lines.size(); i++)
    {
        int from_cnt = 0;
        int to_cnt = 0;
        int from = arr[i].start;
        int to = from + 999;
        int from2 = arr[i].end;
        int to2 = from2 + 999;
        for(int j = 0; j < lines.size(); j++)
        {
            if((arr[j].start >= from && arr[j].start <= to) || (arr[j].end >= from && arr[j].end <= to) || (arr[j].start <= from && arr[j].end >= to))
                from_cnt++;
            if((arr[j].start >= from2 && arr[j].start <= to2) || (arr[j].end >= from2 && arr[j].end <= to2) || (arr[j].start <= from2 && arr[j].end >= to2)) 
                to_cnt++;
        }
        if(from_cnt > answer)
            answer = from_cnt;
        if(to_cnt > answer)
            answer = to_cnt;
    }
    return answer;
}