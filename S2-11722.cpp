#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> vc = vector<int>(N);
    for (int i = 0; i < N; i++) {
        cin >> vc[i];
    }

    int dp[1001] = { 0, };
    for (int i = 0; i < N; i++) {
        dp[i] = 1;
        for (int j = 0; j <= i; j++) {
            if (vc[i] < vc[j] && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < N; i++) {
        if (dp[i] > ans) {
            ans = dp[i];
        }
    }

    cout << ans;

    return 0;
}