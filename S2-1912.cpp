#include <iostream>
#include <algorithm>
using namespace std;

int arr[100001];
int dp[100001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int ans = INT32_MIN;
    for (int i = 0; i < n; i++) {
        dp[i] = max(arr[i], dp[i - 1] + arr[i]);
        ans = max(ans, dp[i]);
    }

    cout << ans;

    return 0;
}