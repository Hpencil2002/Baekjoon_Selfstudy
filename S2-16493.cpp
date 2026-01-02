#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int ans;
int d[21], p[21];
int dp[21][201];

int main() {
    cin >> N >> M;
    for (int i = 1; i <= M; i++) {
        cin >> d[i] >> p[i];
    }

    for (int i = 1; i <= M; i++) {
        for (int j = N; j >= 0; j--) {
            if (j - d[i] >= 0) {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - d[i]] + p[i]);
            }
            else {
                dp[i][j] = dp[i - 1][j];
            }

            ans = max(ans, dp[i][j]);
        }
    }

    cout << ans;

    return 0;
}