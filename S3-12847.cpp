#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    long long arr[100001] = { 0, };
    for (int i = 1; i < n + 1; i++) {
        cin >> arr[i];
        arr[i] = arr[i - 1] + arr[i];
    }

    long long ans = 0;
    for (int i = 0; i < n - m; i++) {
        long long sum = arr[i + m] - arr[i];

        if (sum > ans) {
            ans = sum;
        }
    }

    cout << ans;

    return 0;
}