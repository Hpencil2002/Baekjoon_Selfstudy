#include <iostream>
using namespace std;

const int mod = 1e9 + 9;
int n;
long long dp[100001][4];

void init() {
    dp[1][1] = dp[2][2] = dp[3][1] = dp[3][2] = dp[3][3] = 1;
    for (int i = 4; i <= 100001; i++) {
        if (i - 1 >= 0) {
            dp[i][1] = (dp[i - 1][2] + dp[i - 1][3]) % mod;
        }
        if (i - 2 >= 0) {
            dp[i][2] = (dp[i - 2][1] + dp[i - 2][3]) % mod;
        }
        if (i - 3 >= 0) {
            dp[i][3] = (dp[i - 3][1] + dp[i - 3][2]) % mod;
        }
    }
}

int main() {
    int T;
    cin >> T;

    init();
    while (T--) {
        cin >> n;

        cout << (dp[n][1] + dp[n][2] + dp[n][3]) % mod << "\n";
    }

    return 0;
}