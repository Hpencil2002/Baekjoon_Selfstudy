#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool check(string str) {
    int len = str.length();

    for (int i = 0; i < len / 2; i++) {
        if (str[i] == str[len - i - 1]) {
            continue;
        }
        else {
            return false;
        }
    }

    return true;
}

void solve() {
    int k;
    cin >> k;

    vector<string> vc = vector<string>(k);
    for (int i = 0; i < k; i++) {
        cin >> vc[i];
    }

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            if (i == j) {
                continue;
            }

            if (check(vc[i] + vc[j])) {
                cout << vc[i] + vc[j] << "\n";
                return;
            }
        }
    }

    cout << "0\n";
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}