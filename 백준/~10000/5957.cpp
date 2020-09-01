#include <iostream>
#include <stack>
#include <deque>
using namespace std;

int main(){
    int n;
    cin >>n;
    stack<int> st_d;
    stack<int> st_c;
    deque<int> finish;

    for(int i=n; i>=1; i--){
        st_d.push(i);
    }
    int a,b;
    while(!st_c.empty() || !st_d.empty()){
        cin >>a>>b;
        if(a==1){
            for(int i=0; i<b; i++){
                if(st_d.empty()) continue;
                st_c.push(st_d.top());
                st_d.pop();
            }
        }
        else{
            for(int i=0; i<b; i++){
                if(st_c.empty()) continue;
                finish.push_front(st_c.top());
                st_c.pop();
            }
        }
    }
    deque<int>::iterator iter;

    for(iter=finish.begin(); iter!=finish.end(); iter++){
        cout<<*iter<<"\n";
    }
}