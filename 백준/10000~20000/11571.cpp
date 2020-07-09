#include<iostream>
#include<memory.h>
using namespace std;
int arr[10001];
int main() {
    int n;
    cin >>n;
    while(n--) {
        int k = 0;
        int start, end;
        memset(arr, -1, sizeof(arr));
        int a, b;
        cin >> a >> b;
        start = end = 0;
 
        cout<<a/b<<".";

        int remain = a % b * 10;
 
        while (true) { 
            a = a % b * 10;
            if (arr[a] != -1) {
                start = arr[a];
                end = k;
                break;
            }
            arr[a] = k++;
        }
         
        for (int i = 0; i < start; i++) {
            cout<<remain/b;
            remain = remain % b * 10;
        }
        cout<<"(";
        for (int i = start; i < end; i++) {
            cout<<remain/b;
            remain = remain % b * 10;
        }
        cout<<")\n";
    }
    return 0;
}