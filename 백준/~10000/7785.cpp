#include <iostream>
#include <set>
#include <string>
using namespace std;

int main() {
    set<string> s;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string name;
        cin >> name;
        string state;
        cin >> state;
        if (state == "enter") {
            s.insert(name);
        }
        else {
            s.erase(name);
        }
    }
    set<string>::reverse_iterator it;
    for (it = s.rbegin(); it != s.rend(); it++) {
        cout << *it << "\n";
    }
}
