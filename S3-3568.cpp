#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> split(string input, char token) {
    vector<string> vc;
    int pre = 0;
    int cur = input.find(token);

    while (cur != string::npos) {
        vc.push_back(input.substr(pre, cur - pre));
        pre = cur + 1;
        cur = input.find(token, pre);
    }
    vc.push_back(input.substr(pre, cur - pre));

    return vc;
}

bool isAlpha(char c) {
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
        return true;
    }

    return false;
}

int main() {
    string str;
    getline(cin, str);

    vector<string> vc = split(str, ' ');

    string type, type_, _var, var;
    for (int i = 0; i < vc.size(); i++) {
        if (i == 0) {
            type = vc[i];
            continue;
        }
        else {
            var = vc[i].substr(0, vc[i].size() - 1);
            type_ = "";
            _var = "";

            for (int i = var.size() - 1; i >= 0; i--) {
                if (isAlpha(var[i])) {
                    _var = var[i] + _var;
                    continue;
                }

                if (var[i] == ']') {
                    type_ += '[';
                }
                else if (var[i] == '[') {
                    type_ += ']';
                }
                else {
                    type_ += var[i];
                }
            }

            cout << type << type_ << ' ' << _var << ";\n";
        }
    }

    return 0;
}