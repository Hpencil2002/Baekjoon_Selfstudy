#include <iostream>
#include <numeric>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        long long arr[101];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        long long ans = 0;
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                ans += gcd(arr[i], arr[j]);
            }
        }

        cout << ans << "\n";
    }

    return 0;
}