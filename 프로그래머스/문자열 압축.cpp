#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int number_len(int a){
    int i=0;
    while(a>0){
        a/=10;
        i++;
    }
    return i;
}

int strcmp(string s1, string s2){
    int i=0;
    while(s1[i] && s2[i]){
        if(s1[i]!=s2[i]){
            break;
        }
        i++;
    }
    return (s1[i]-s2[i]);
}

int solution(string s) {
    int answer = s.size();
    for(int i=1; i<=s.size()/2; i++){
        string str=s.substr(0,i);
        int cnt=1;
        int len=s.size()%i;
        for(int j=i; j<s.size()-i+1; j+=i){
            string str2=s.substr(j,i);
            if(strcmp(str,str2)==0) {
                cnt++;
                continue;
            }
            else{
                if(cnt>=2){
                    len+=number_len(cnt)+i;
                }
                else{
                    len+=i;
                }
                str=str2;
                cnt=1;
            }
        }
        if(cnt>=2){
            len+=number_len(cnt)+i;
        }
        else{
            len+=i;
        }
        answer=min(len,answer);
    }
    return answer;
}