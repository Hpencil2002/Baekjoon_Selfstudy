#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string name;
int alp[26] = {0, };

int main() {
    cin >> name;

    for (int i = 0; i < name.size(); i++) {
        alp[name[i] - 'A'] += 1;
    }

    int err = 0;
    int mid = -1;

    for (int i = 0; i < 26; i++) {
        if (alp[i] > 0) {
            if (alp[i] % 2 == 1) {
                mid = i;
                alp[i] -= 1;
                err += 1;
            }
        }
    }

    if (err > 1) {
        cout << "I'm Sorry Hansoo\n";
    }
    else {
        string ans = "";
        string tmp = "";

        for (int i = 0; i < 26; i++) {
            if (alp[i] > 0) {
                for (int j = 0; j < alp[i] / 2; j++) {
                    ans += i + 'A';
                }
            }
        }

        tmp = ans;
        reverse(tmp.begin(), tmp.end());
        if (mid != -1) {
            ans += mid + 'A';
        }
        ans += tmp;

        cout << ans << "\n";
    }

    return 0;
}