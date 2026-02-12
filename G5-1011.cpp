#include <iostream>
#include <cmath>
using namespace std;

long long x, y;
long long cnt;
long long ans;

int main() {
    int T;
    cin >> T;

    while (T--) {
        cin >> x >> y;

        cnt = 0;
        ans = 0;
        while (cnt * cnt <= y - x) {
            cnt += 1;
        }

        cnt -= 1;
        ans = 2 * cnt - 1;

        long long rem = y - x - cnt * cnt;
        rem = (long long)ceil((double)rem / (double)cnt);
        ans += rem;

        cout << ans << "\n";
    }

    return 0;
}