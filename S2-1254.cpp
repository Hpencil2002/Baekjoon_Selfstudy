#include <iostream>
#include <string>
using namespace std;

bool check(string str) {
    int cnt = str.size() / 2;

    for (int i = 0; i < cnt; i++) {
        if (str[i] != str[str.size() - 1 - i]) {
            return false;
        }
    }

    return true;
}

int main() {
    string S;
    cin >> S;

    int ans = S.size() * 2 - 1;

    for (int i = 0; i < S.size(); i++) {
        string str = S.substr(i, S.size() - i);

        if (check(str)) {
            ans = S.size() + i;
            break;
        }
    }

    cout << ans;

    return 0;
}