#include <iostream>
#include <algorithm>
using namespace std;

int N;
int arr[1500010][2];
int dp[1500010];
int ans;

int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i][0] >> arr[i][1];
    }

    for (int i = 1; i <= N + 1; i++) {
        ans = max(ans, dp[i]);

        if (i + arr[i][0] > N + 1) {
            continue;
        }

        dp[i + arr[i][0]] = max(dp[i + arr[i][0]], ans + arr[i][1]);
    }

    cout << ans;

    return 0;
}