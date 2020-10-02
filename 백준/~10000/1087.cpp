#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;
int arr[51][4];
int n;

double f(double t){
    double high_x=arr[0][0]+arr[0][2]*t;
    double low_x=arr[0][0]+arr[0][2]*t;
    double high_y=arr[0][1]+arr[0][3]*t;
    double low_y=arr[0][1]+arr[0][3]*t;
    for(int i=1; i<n; i++){
        high_x=max(high_x,arr[i][0]+arr[i][2]*t);
        low_x=min(low_x,arr[i][0]+arr[i][2]*t);
        high_y=max(high_y,arr[i][1]+arr[i][3]*t);
        low_y=min(low_y,arr[i][1]+arr[i][3]*t);
    }
    return max(high_x-low_x,high_y-low_y);
}

int main(){
    cin >>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<4; j++){
            cin >>arr[i][j];
        }
    }
    double lo=0;
    double hi=2000;
    for(int i=0; i<1000 && lo<hi; i++){
        double a = (lo*2+hi)/3;
        double b = (lo+hi*2)/3;
        if(f(a)<f(b)){
            hi=b;
        }
        else{
            lo=a;
        }
    }
    printf("%.9lf\n",f(lo));
}