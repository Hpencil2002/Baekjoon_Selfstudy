#include <iostream>
#include <algorithm>
using namespace std;

int arr[10][10];
int dp[7][7][3];

int main() {
    int N, M;
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];

            dp[i][j][0] = dp[i][j][1] = dp[i][j][2] = arr[i][j];
            if (j == 0) {
                dp[i][j][0] = 1000;
            }
            if (j == M - 1) {
                dp[i][j][2] = 1000;
            }
        }
    }

    for (int i = 1; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (j != 0) {
                dp[i][j][0] += min(dp[i - 1][j - 1][1], dp[i - 1][j - 1][2]);
            }

            dp[i][j][1] += min(dp[i -1][j][0], dp[i - 1][j][2]);

            if (j != M - 1) {
                dp[i][j][2] += min(dp[i - 1][j + 1][0], dp[i - 1][j + 1][1]);
            }
        }
    }

    int ans = 1000;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < 3; j++) {
            ans = min(ans, dp[N - 1][i][j]);
        }
    }

    cout << ans;

    return 0;
}