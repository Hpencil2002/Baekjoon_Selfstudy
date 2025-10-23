#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool check(string a, string b) {
    if (a.size() != b.size()) {
        return false;
    }

    for (int i = 0; i < b.size(); i++) {
        string tmp = b.substr(i, b.size() - i) + b.substr(0, i);

        if (a == tmp) {
            return true;
        }
    }

    return false;
}

int main() {
    int N;
    cin >> N;

    vector<string> vc;
    for (int i = 0; i < N; i++) {
        string str;
        cin >> str;
        vc.push_back(str);
    }

    for (int i = 0; i <vc.size(); i++) {
        for (int j = i + 1; j < vc.size(); j++) {
            if (i == j) {
                continue;
            }

            if (check(vc[i], vc[j])) {
                vc[j] = vc[i];
            }
        }
    }

    sort(vc.begin(), vc.end());

    vc.erase(unique(vc.begin(), vc.end()), vc.end());

    cout << vc.size();

    return 0;
}