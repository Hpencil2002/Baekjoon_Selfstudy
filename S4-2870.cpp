#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(string a, string b) {
    if (a.size() == b.size()) {
        return a < b;
    }
    else {
        return a.size() < b.size();
    }
}

string zero(string str) {
    string num = "";
    int flag = 0;

    for (int i = 0; i < str.size(); i++) {
        if (str[i] != '0') {
            num += str[i];
            flag = 1;
        }
        else if (flag && str[i] == '0') {
            num += '0';
        }
    }

    if (num == "") {
        return "0";
    }
    else {
        return num;
    }
}

int main() {
    int N;
    cin >> N;

    vector<string> vc;
    string str, num = "";
    while (N--) {
        cin >> str;

        num = "";
        for (int i = 0; i < str.size(); i++) {
            if (str[i] >= '0' && str[i] <= '9') {
                num += str[i];
            }
            else {
                if (num != "") {
                    vc.push_back(zero(num));
                }
                num = "";
            }
        }

        if (num != "") {
            vc.push_back(zero(num));
        }
    }

    sort(vc.begin(), vc.end(), comp);

    for (auto k : vc) {
        cout << k << "\n";
    }

    return 0;
}