#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    getline(cin, str);

    string ans = "";
    bool flag = false;
    for (int i = 0; i < str.size(); i++) {
        if (ans.size() == 0 && str[i] == 'U') {
            ans += str[i];
        }
        else if (ans.size() == 1 && str[i] == 'C') {
            ans += str[i];
        }
        else if (ans.size() == 2 && str[i] == 'P') {
            ans += str[i];
        }
        else if (ans.size() == 3 && str[i] == 'C') {
            ans += str[i];
        }

        if (ans.size() == 4) {
            flag = true;
        }
        else {
            flag = false;
        }
    }

    if (flag) {
        cout << "I love UCPC";
    }
    else {
        cout << "I hate UCPC";
    }

    return 0;
}