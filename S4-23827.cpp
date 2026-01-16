#include <iostream>
using namespace std;

#define mod 1000000007

int N;
long long arr[500010];
long long sums[500010];
long long ans;

int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];

        sums[i] = sums[i - 1] + arr[i];
        ans += arr[i] * sums[i - 1];
        ans %= mod;
    }

    cout << ans;

    return 0;
}