#include <iostream>
#include <string>
#include <deque>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >>t;
    while(t--){
        string str;
        cin >>str;
        string arr;
        int n;
        cin >>n;
        cin.ignore();
        getline(cin,arr);
        deque<int> dq;
        char trash;
        for(int i=0; i<arr.size(); i++){
            bool is_num=false;
            string num="";
            while(arr[i]>='0' && arr[i]<='9'){
                is_num=true;
                num+=arr[i];
                i++;
            }
            if(is_num && (arr[i]==',' || arr[i]==']')){
                dq.push_back(stoi(num));
            }
        }
        bool check=true;
        bool dir=true;
        for(int i=0; i<str.size(); i++){
            if(str[i]=='R'){
                dir=!dir;
            }
            else{
                if(!dq.empty()){
                    if(dir){
                        dq.pop_front();
                        n--;
                    }
                    else{
                        dq.pop_back();
                        n--;
                    }
                }
                else{
                    cout<<"error\n";
                    check =false;
                    break;
                }
            }
        }
        if(!dir){
            int p=0;
            int q=n-1;
            while(p<q){
                int temp=dq[p];
                dq[p]=dq[q];
                dq[q]=temp;
                p++;
                q--;
            }
        }
        if(check){
            cout<<"[";
            for(int i=0; i<dq.size(); i++){
                cout<<dq[i];
                if(i!=dq.size()-1) cout<<",";
            }
            cout<<"]\n";
        }
    }
}