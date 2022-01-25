#include <iostream>
using namespace std;

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    int num = 0;


    while (a != b) {
        a = (a + 1) / 2;
        b = (b + 1) / 2;
        num++;
    }

    cout << num;
}
