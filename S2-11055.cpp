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

    int ans = 0;
    int dp[1001] = { 0, };
    for (int i = 0; i < N; i++) {
        dp[i] = vc[i];
        for (int j = 0; j < i; j++) {
            if (vc[j] < vc[i] && dp[i] < dp[j] + vc[i]) {
                dp[i] = dp[j] + vc[i];
            }
        }

        if (ans < dp[i]) {
            ans = dp[i];
        }
    }

    cout << ans;

    return 0;
}