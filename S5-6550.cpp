#include <iostream>
#include <string>
using namespace std;

int main() {
    string s, t;

    while (cin >> s >> t) {
        int index = 0;
        bool flag = false;

        for (int i = 0; i < t.size(); i++) {
            if (s[index] == t[i]) {
                index += 1;
            }

            if (index == s.size()) {
                flag = true;
                break;
            }
        }

        if (flag) {
            cout << "Yes\n";
        }
        else {
            cout << "No\n";
        }
    }

    return 0;
}