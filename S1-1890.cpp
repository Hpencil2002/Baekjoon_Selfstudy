#include <iostream>
using namespace std;

int N;
int arr[100][100];
long long dp[100][100];

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }

    dp[0][0] = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (dp[i][j] == 0 || (i == N - 1 && j == N - 1)) {
                continue;
            }

            int val = arr[i][j];
            int down = val + i;
            int right = val + j;

            if (down < N) {
                dp[down][j] = dp[down][j] + dp[i][j];
            }
            if (right < N) {
                dp[i][right] = dp[i][right] + dp[i][j];
            }
        }
    }

    cout << dp[N - 1][N - 1];

    return 0;
}