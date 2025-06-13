#include <iostream>
#include <algorithm>
using namespace std;

int N;
int ans = 0;
int A[1010];
int dp[1010] = {0, };

int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }

    for (int i = 1; i <= N; i++) {
        dp[i] = 1;
        for (int j = i - 1; j >= 1; j--) {
            if (A[i] > A[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }

        ans = max(dp[i], ans);
    }

    cout << ans;

    return 0;
}