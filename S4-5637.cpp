#include <iostream>
#include <string>
using namespace std;

string input;
string ans;

string preprocess(string str) {
    string res = "";

    for (auto iter = str.begin(); iter != str.end(); iter++) {
        if (isalpha(*iter) || *iter == '-') {
            res += *iter;
        }
    }

    return res;
}

int main() {
    while (true) {
        cin >> input;
        if (input == "E-N-D") {
            break;
        }

        input = preprocess(input);
        ans = ans.length() < input.length() ? input : ans;
    }

    for (auto iter = ans.begin(); iter != ans.end(); iter++) {
        *iter = tolower(*iter);
    }

    cout << ans;

    return 0;
}