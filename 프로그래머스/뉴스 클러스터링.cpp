#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
vector<pair<string,int>> v1;
vector<pair<string,int>> v2;

bool is_alpha(char a){
    if((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z'))
        return true;
    return false;
}

int strcmp(string a, string b){
    int i = 0;
    
    while(a[i] && b[i]){
        if(a[i] >= 'a' && a[i] <= 'z'){
            a[i] -= 'a' - 'A';
        }
        if(b[i] >= 'a' && b[i] <= 'z'){
            b[i] -= 'a' - 'A';
        }
        if(a[i] != b[i])
            break;
        i++;
    }
    return (a[i]-b[i]);
}

int solution(string str1, string str2) {
    int answer = 0;
    for(int i = 0; i<str1.size()-1; i++){
        string str = "";
        str+=str1[i];
        str+=str1[i+1];
        bool check=false;
        if(!is_alpha(str1[i]) || !is_alpha(str1[i+1])) continue;
        for(int j = 0; j<v1.size(); j++){
            if(strcmp(v1[j].first,str) == 0){
                v1[j].second++;
                check =true;
            }
        }
        if(check) continue;
        v1.push_back({str,1});
    }
    for(int i = 0; i<str2.size()-1; i++){
        string str = "";
        str+=str2[i];
        str+=str2[i+1];
        bool check = false;
        if(!is_alpha(str2[i]) || !is_alpha(str2[i+1])) continue;
        for (int j = 0; j<v2.size(); j++){
            if(strcmp(v2[j].first,str)==0){
                v2[j].second++;
                check=true;
            }
        }
        if(check) continue;
        v2.push_back({str,1});
    }
    vector<pair<string,int>> uni;
    vector<pair<string,int>> inter;
    for(int i=0; i<v1.size(); i++){
        for(int j=0; j<v2.size(); j++){
            if(strcmp(v1[i].first, v2[j].first)==0){
                inter.push_back({v1[i].first,min(v1[i].second,v2[j].second)});
            }
        }
    }
    
    for(int i =0; i<v1.size(); i++){
        uni.push_back(v1[i]);
    }
    for(int j=0; j<v2.size(); j++){
        bool check = false;
        for(int i=0; i<uni.size(); i++){
            if(strcmp(v2[j].first, uni[i].first)==0){
                check =true;
                uni[i].second = max(uni[i].second, v2[j].second);
                break;
            }
        }
        if(!check)
            uni.push_back(v2[j]);
    }
    double a = 0;
    double b = 0;
    for(int i = 0; i<uni.size(); i++){
        a += uni[i].second;
    }
    for(int i = 0; i<inter.size(); i++){
        b += inter[i].second;
    }
    if(a == 0)
        return (65536);
    double c = b / a;
    c *= 65536;
    answer = (int)c;
    return answer;
}