#include <iostream>
using namespace std;

int N, S, M;
int arr[110];
bool dp[110][1010];

int main() {
    cin >> N >> S >> M;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    if (S + arr[1] <= M) {
        dp[1][S + arr[1]] = true;
    }
    if (S - arr[1] >= 0) {
        dp[1][S - arr[1]] = true;
    }

    for (int i = 2; i <= N; i++) {
        for (int j = 0; j <= M; j++) {
            if (dp[i -1][j]) {
                if (j + arr[i] <= M) {
                    dp[i][j + arr[i]] = true;
                }
                if (j - arr[i] >= 0) {
                    dp[i][j - arr[i]] = true;
                }
            }
        }
    }

    for (int i = M; i >= 0; i--) {
        if (dp[N][i]) {
            cout << i;

            return 0;
        }
    }

    cout << -1;

    return 0;
}