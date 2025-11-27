#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[1001];

int main() {
    int N;
    cin >> N;

    vector<int> vc = vector<int>(N);
    for (int i = 0; i < N; i++) {
        cin >> vc[i];
        dp[i] = 1;
    }

    int ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < i; j++) {
            if (vc[i] > vc[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }

        ans = max(ans, dp[i]);
    }

    cout << ans;

    return 0;
}