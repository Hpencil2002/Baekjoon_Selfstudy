#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int cnt[26];
string str;

bool check() {
    for (int i = 0; i < str.size(); i++) {
        char c = str[i];

        if (++cnt[c - 'A'] == 3) {
            if (i + 1 == str.size() || str[i + 1] != c) {
                return true;
            }

            cnt[c - 'A'] = 0;
            i++;
        }
    }

    return false;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        cin >> str;

        memset(cnt, 0, sizeof(cnt));

        cout << (check() ? "FAKE\n" : "OK\n");
    }

    return 0;
}