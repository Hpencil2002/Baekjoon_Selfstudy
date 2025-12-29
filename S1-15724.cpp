#include <iostream>
using namespace std;

int N, M, K;
int x1, y1, x2, y2;
int arr[1025][1025];
int dp[1025][1025];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 1; i <= N; i++) {
        int tmp = 0;

        for (int j = 1; j <= M; j++) {
            tmp += arr[i][j];

            if (i == 1) {
                dp[i][j] = tmp;
            }
            else {
                dp[i][j] = tmp + dp[i - 1][j];
            }
        }
    }

    cin >> K;
    while (K--) {
        cin >> x1 >> y1 >> x2 >> y2;

        int ans = dp[x2][y2] - (dp[x2][y1 - 1] + dp[x1 - 1][y2]) + dp[x1 - 1][y1 - 1];
        cout << ans << "\n";
    }

    return 0;
}