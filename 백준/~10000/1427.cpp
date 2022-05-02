#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
string arr[100];

bool compare(string a, string b) {
    return a > b;
}

int main() {
    string str;
    cin >> str;
    for (int i = 0; i < str.size(); i++) {
        arr[i] = str[i];
    }

    sort(arr, arr + str.size(),compare);

    for (int i = 0; i < str.size(); i++) {
        cout << arr[i];
    }

}
