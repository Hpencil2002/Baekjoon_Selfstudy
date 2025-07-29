#include <iostream>
#include <string>
using namespace std;

int N;
string s;
string sen[] = { "000000", "001111", "010011", "011100", "100110", "101001", "110101", "111010" };

int cmp(string str, int index) {
    int cnt = 0;

    for (int i = 0; i < 6; i++) {
        if (sen[index][i] != str[i]) {
            cnt += 1;
        }
    }

    return cnt;
}

int main() {
    cin >> N >> s;

    string ans = "";
    for (int i = 0; i < N; i++) {
        string tmp = s.substr(i * 6, 6);
        bool ok = false;

        for (int j = 0; j < 8; j++) {
            if (cmp(tmp, j) <= 1) {
                ok = true;
                ans += ('A' + j);
                break;
            }
        }

        if (!ok) {
            cout << i + 1;
            return 0;
        }
    }

    cout << ans;

    return 0;
}