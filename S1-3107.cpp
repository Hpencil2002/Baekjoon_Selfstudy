#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string str, ans;
vector<string> result, answer, tmp;
bool flag = false;

vector<string> split(string str, string delimiter) {
    vector<string> res;
    size_t prev = 0, cur = str.find(delimiter);

    while (cur != string::npos) {
        string sub = str.substr(prev, cur - prev);
        res.push_back(sub);

        prev = cur + 1;
        cur = str.find(delimiter, prev);
    }
    res.push_back(str.substr(prev, cur - prev));

    if (str.find("::") != string::npos) {
        flag = true;
    }

    return res;
}

int main() {
    cin >> str;

    result = split(str, ":");

    if (result.size() != 8) {
        for (int i = 0; i < result.size(); i++) {
            if (result[i].length() == 0 && flag) {
                for (int j = 0; j < 9 - result.size(); j++) {
                    tmp.push_back("0000");
                }

                flag = false;
            }
            else {
                tmp.push_back(result[i]);
            }
        }

        result = tmp;
    }

    for (int i = 0; i < 8; i++) {
        if (result[i].length() < 4) {
            string tmp;

            for (int j = 0; j < 4 - result[i].length(); j++) {
                tmp += '0';
            }
            tmp += result[i];

            answer.push_back(tmp);
        }
        else {
            answer.push_back(result[i]);
        }
    }

    for (int i = 0; i < 8; i++) {
        ans += i == 7 ? answer[i] : answer[i] + ":";
    }

    cout << ans;

    return 0;
}