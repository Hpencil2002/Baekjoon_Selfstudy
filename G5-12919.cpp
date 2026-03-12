#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string S, T;
string tmp;

void solve(string s, string t) {
    if (s == t) {
        cout << "1\n";

        exit(0);
    }

    if (s.size() >= t.size()) {
        return;
    }

    if (t[t.size() - 1] == 'A') {
        tmp = t;
        tmp.erase(tmp.size() - 1);
        solve(s, tmp);
    }
    if (t[0] == 'B') {
        tmp = t;
        tmp.erase(tmp.begin());
        reverse(tmp.begin(), tmp.end());
        solve(s, tmp);
    }
}

int main() {
    cin >> S >> T;

    solve(S, T);

    cout << "0\n";

    return 0;
}