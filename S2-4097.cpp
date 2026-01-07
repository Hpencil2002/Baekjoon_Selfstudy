#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int ans;
vector<int> vc;
vector<int> dp;

int main() {
    while (true) {
        cin >> N;
        if (N == 0) {
            return 0;
        }

        ans = -(1e5 + 1);
        vc = vector<int>(N + 1, 0);
        dp = vector<int>(N + 1);

        for (int i = 1; i <= N; i++) {
            cin >> vc[i];
        }

        for (int i = 1; i <= N; i++) {
            dp[i] = max(dp[i - 1] + vc[i], vc[i]);
            ans = max(ans, dp[i]);
        }

        cout << ans << "\n";
    }
}