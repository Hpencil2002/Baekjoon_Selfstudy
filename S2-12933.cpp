#include <iostream>
#include <string>
using namespace std;

int ans;
bool check[2501] = { false, };

int main() {
    string str;
    cin >> str;

    for (int i = 0; i < str.size(); i++) {
        string tmp = "";
        bool valid = false;
        int index[5] = { 0, };

        for (int j = i; j < str.size(); j++) {
            if (check[j] == false) {
                if (str[j] == 'q' && tmp == "") {
                    index[0] = j;
                    tmp += "q";
                }
                if (str[j] == 'u' && tmp == "q") {
                    index[1] = j;
                    tmp += "u";
                }
                else if (str[j] == 'a' && tmp == "qu") {
                    index[2] = j;
                    tmp += "a";
                }
                else if (str[j] == 'c' && tmp == "qua") {
                    index[3] = j;
                    tmp += "c";
                }
                else if (str[j] == 'k' && tmp == "quac") {
                    index[4] = j;
                    tmp += "k";
                }
            }

            if (tmp == "quack") {
                tmp = "";

                if (index[0] < index[1] && index[1] < index[2] && index[2] < index[3] && index[3] < index[4]) {
                    if (!valid) {
                        valid = true;
                        ans += 1;
                    }

                    check[index[0]] = true;
                    check[index[1]] = true;
                    check[index[2]] = true;
                    check[index[3]] = true;
                    check[index[4]] = true;
                }
            }
        }
    }

    for (int i = 0; i < str.size(); i++) {
        if (check[i] == false) {
            cout << -1;

            return 0;
        }
    }

    cout << ans;

    return 0;
}