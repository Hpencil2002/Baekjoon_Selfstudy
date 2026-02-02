#include <iostream>
using namespace std;

#define mod 1234567

int N;
int ans;
int dp[1001][10];

int main() {
    int T;
    cin >> T;

    for (int i = 0; i < 10; i++) {
        dp[1][i] = 1;
    }
    for (int i =2; i <= 1000; i++) {
        for (int j = 0; j < 10; j++) {
            if (j == 0) {
                dp[i][j] = dp[i -1][7];
            }
            else if (j == 1) {
                dp[i][j] = dp[i - 1][2] + dp[i - 1][4];
            }
            else if (j == 2) {
                dp[i][j] = dp[i - 1][1] + dp[i - 1][3] + dp[i - 1][5];
            }
            else if (j == 3) {
                dp[i][j] = dp[i - 1][2] + dp[i - 1][6];
            }
            else if (j == 4) {
                dp[i][j] = dp[i - 1][1] + dp[i - 1][5] + dp[i - 1][7];
            }
            else if (j == 5) {
                dp[i][j] = dp[i - 1][2] + dp[i - 1][4] + dp[i - 1][6] + dp[i - 1][8];
            }
            else if (j == 6) {
                dp[i][j] = dp[i - 1][3] + dp[i - 1][5] + dp[i - 1][9];
            }
            else if (j == 7) {
                dp[i][j] = dp[i - 1][0] + dp[i - 1][4] + dp[i - 1][8];
            }
            else if (j == 8) {
                dp[i][j] = dp[i - 1][5] + dp[i - 1][7] + dp[i - 1][9];
            }
            else if (j == 9) {
                dp[i][j] = dp[i - 1][6] + dp[i - 1][8];
            }

            dp[i][j] %= mod;
        }
    }

    while (T--) {
        ans = 0;
        cin >> N;

        for (int i = 0; i < 10; i++) {
            ans += dp[N][i] % mod;
        }

        cout << ans % mod << "\n";
    }

    return 0;
}