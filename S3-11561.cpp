#include <iostream>
#include <algorithm>
using namespace std;

int T;
unsigned long long N;
unsigned long long ans;

int main() {
    cin >> T;
    while (T--) {
        cin >> N;

        unsigned long long start = 1;
        unsigned long long end = 1e16;
        ans = 0;

        while (start <= end) {
            unsigned long long mid = (start + end) / 2;

            if (mid * (mid + 1) <= 2 * N) {
                ans = max(ans, mid);
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }

        cout << ans << "\n";
    }

    return 0;
}