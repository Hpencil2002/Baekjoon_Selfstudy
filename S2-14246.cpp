#include <iostream>
using namespace std;

long long n, k;
long long arr[100001];
long long presum[100001];
long long ans;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        presum[i] = presum[i - 1] + arr[i];
    }
    cin >> k;

    for (int i = 1; i <= n; i++) {
        int j = 0;

        while (presum[i] - presum[j] > k) {
            ans += 1;
            j += 1;

            if (j == i) {
                break;
            }
        }
    }

    cout << ans;

    return 0;
}