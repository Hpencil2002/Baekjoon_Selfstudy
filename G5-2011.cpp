#include <iostream>
#include <string>
using namespace std;

#define mod 1000000

string str;
int dp[5001];

int main() {
    cin >> str;
    if (str[0] == '0') {
        cout << 0;

        return 0;
    }

    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= str.size(); i++) {
        if (str[i - 1] != '0') {
            dp[i] = dp[i - 1] % mod;
        }

        int tmp = (str[i - 2] - '0') * 10 + (str[i - 1] - '0');
        if (tmp >= 10 && tmp <= 26) {
            dp[i] = (dp[i] + dp[i - 2]) % mod;
        }
    }

    cout << dp[str.size()];

    return 0;
}