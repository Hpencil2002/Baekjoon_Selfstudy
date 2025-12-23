#include <iostream>
#include <algorithm>
using namespace std;

int n, l;

int main() {
    int T;
    cin >> T;

    while (T--) {
        cin >> l >> n;

        int minTime = 0;
        int maxTime = 0;

        for (int i = 0; i < n; i++) {
            int pos;
            cin >> pos;

            int sht = min(pos, l - pos);
            int lng = max(pos, l - pos);

            minTime = max(minTime, sht);
            maxTime = max(maxTime, lng);
        }

        cout << minTime << ' ' << maxTime << "\n";
    }

    return 0;
}