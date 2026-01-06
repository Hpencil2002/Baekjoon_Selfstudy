#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> dp;

int main() {
    cin >> N >> M;
    dp = vector<int>(N + 1);

    dp[0] = 1;
    for (int i = 0; i < N + 1; i++) {
        if (i + 1 < N + 1) {
            dp[i + 1] = (dp[i] + dp[i + 1]) % 1000000007;
        }

        if (i + M < N + 1) {
            dp[i + M] = (dp[i] + dp[i + M]) % 1000000007;
        }
    }

    cout << dp[N];

    return 0;
}