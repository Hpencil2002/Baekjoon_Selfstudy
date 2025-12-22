#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

int N;
string str;
vector<string> orders;

vector<string> getSplit(string str) {
    stringstream ss(str);
    vector<string> res;
    string t;

    while (getline(ss, t, ' ')) {
        res.push_back(t);
    }

    return res;
}

bool check(char c) {
    if (c >= 65 && c <= 90) {
        return true;
    }

    return false;
}

string getKey(string str, vector<int>& vc) {
    bool select = false;
    vector<string> word = getSplit(str);
    string tmp = "";

    for (int i = 0; i < word.size(); i++) {
        char c = word[i][0];
        if (check(c)) {
            c += 32;
        }

        if (!select && vc[c - 'a'] == 0) {
            vc[c - 'a'] = 1;
            string key = "[" + word[i].substr(0, 1) + "]";
            word[i].replace(0, 1, key);
            select = true;
        }

        tmp += word[i];
        if (i < word.size() - 1) {
            tmp += " ";
        }
    }
    str = tmp;

    if (!select) {
        for (int i = 0; i < str.size(); i++) {
            char c = str[i];
            if (check(c)) {
                c += 32;
            }

            if (c != ' ' && vc[c - 'a'] == 0) {
                vc[c - 'a'] = 1;
                string key = "[" + str.substr(i, 1) + "]";
                str.replace(i, 1, key);
                break;
            }
        }
    }

    return str;
}

int main() {
    vector<int> vc = vector<int>(27, 0);

    cin >> N;
    cin.ignore();

    for (int i = 0; i < N; i++) {
        getline(cin, str);
        orders.push_back(str);
    }

    for (int i = 0; i < N; i++) {
        orders[i] = getKey(orders[i], vc);
        cout << orders[i] << "\n";
    }

    return 0;
}