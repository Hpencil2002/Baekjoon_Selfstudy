#include <iostream>
#include <set>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    set<int> s;
    for (int i = 0; i < a; i++) {
        int num;
        cin >> num;
        s.insert(num);
    }

    set<int>::iterator check;
    set<int>::iterator t;
    for (int i = 0; i < b; i++) {
        int num;
        cin >> num;

        check = s.find(num);
        if (check == s.end()) {
            continue;
        }
        else {
            s.erase(check);
        }
    }

    cout << s.size() << "\n";

    for (t = s.begin(); t != s.end(); t++) {
        cout << *t << ' ';
    }

    return 0;
}