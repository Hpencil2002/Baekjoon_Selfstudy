#include <iostream>
#include <string>
#include <vector>
using namespace std;

string str;

int main() {
    while (true) {
        cin >> str;
        if (str == "*") {
            return 0;
        }

        int len = 1;
        bool flag = true;

        while (len < str.length()) {
            vector<string> vc;

            for (int i = 0; i < str.length(); i++) {
                if (i + len >= str.length()) {
                    break;
                }

                string tmp = "";
                tmp += str[i];
                tmp += str[i + len];
                vc.push_back(tmp);
            }

            for (int i = 0; i < vc.size(); i++) {
                for (int j = i + 1; j < vc.size(); j++) {
                    if (vc[i] == vc[j]) {
                        flag = false;
                        break;
                    }
                }
            }

            if (!flag) {
                break;
            }

            len += 1;
        }

        if (flag) {
            cout << str << " is surprising.\n";
        }
        else {
            cout << str << " is NOT surprising.\n";
        }
    }
}