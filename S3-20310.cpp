#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string S;
    cin >> S;

    int zero = count(S.begin(), S.end(), '0');
    int one = count(S.begin(), S.end(), '1');

    zero /= 2;
    one /= 2;

    string ans = "";
    for (int i = 0; i < S.size(); i++) {
        if (S[i] == '1' && one > 0) {
            one -= 1;
        }
        else {
            ans += S[i];
        }
    }

    S = ans;
    ans = "";
    for (auto it = S.rbegin(); it != S.rend(); it++) {
        if (*it == '0' && zero > 0) {
            zero -= 1;
        }
        else {
            ans += *it;
        }
    }

    reverse(ans.begin(), ans.end());

    cout << ans;

    return 0;
}