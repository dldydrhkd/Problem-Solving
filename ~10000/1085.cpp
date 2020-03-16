#include <iostream>
using namespace std;
int x,y,w,h;

int main(){
        cin >>x>>y>>w>>h;
        
       int dist=min(h-y,w-x);
       dist=min(dist,y);
       dist=min(dist,x);

       cout<<dist;

}