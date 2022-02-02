#include <iostream>
#include <set>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    set<string> s1;
    set<string> s2;

    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        s1.insert(str);
    }

    for (int i = 0; i < m; i++) {
        string str;
        cin >> str;
        if (s1.find(str) != s1.end()) {
            s2.insert(str);
        }
    }

    set<string>::iterator it;
    cout << s2.size() << "\n";
    for (it = s2.begin(); it != s2.end(); it++) {
        cout << *it << "\n";
    }
}
