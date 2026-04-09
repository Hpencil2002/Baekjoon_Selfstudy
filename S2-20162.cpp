#include <iostream>
#include <algorithm>
using namespace std;

int N;
int ans;
int arr[1001];
int dp[1001];

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        dp[i] = arr[i];
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j] && dp[j] + arr[i] > dp[i]) {
                dp[i] = dp[j] + arr[i];
            }
        }

        ans = max(ans, dp[i]);
    }

    cout << ans;

    return 0;
}