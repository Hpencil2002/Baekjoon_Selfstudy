#include <iostream>
using namespace std;

#define MAX 100001

long long arr[MAX];
long long sum[MAX];

int main() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        sum[i] = sum[i - 1] + arr[i];
    }

    long long ans = 0;
    for (int i = 1; i < n; i++) {
        ans += (sum[n] - sum[i]) * arr[i];
    }

    cout << ans;

    return 0;
}