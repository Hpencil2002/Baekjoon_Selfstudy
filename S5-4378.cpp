#include <iostream>
#include <string>
using namespace std;

string str[4] = {
    "`1234567890-=",
    "QWERTYUIOP[]\\",
    "ASDFGHJKL;'",
    "ZXCVBNM,./"
};

int main() {
    string s;

    while (getline(cin, s)) {
        for (int t = 0; t < s.size(); t++) {
            if (s[t] == ' ') {
                cout << s[t];
                continue;
            }

            bool found = false;
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < str[i].size(); j++) {
                    if (s[t] == str[i][j]) {
                        cout << str[i][j - 1];
                        found = true;

                        break;
                    }
                }

                if (found) {
                    break;
                }
            }
        }

        cout << "\n";
    }

    return 0;
}