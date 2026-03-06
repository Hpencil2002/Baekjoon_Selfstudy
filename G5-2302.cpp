#include <iostream>
using namespace std;

int N, M;
int ans = 1;
int dp[45];
int vip[45];

int main() {
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> vip[i];
    }

    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= N; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    int start = 0;
    for (int i = 0; i < M; i++) {
        int end = vip[i];
        ans *= dp[end - start - 1];

        start = end;
    }
    ans *= dp[N - start];

    cout << ans;

    return 0;
}