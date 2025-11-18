#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        vector<int> vc = vector<int>(N);
        for (int i = 0; i < N; i++) {
            cin >> vc[i];
        }

        long long ans = 0;
        int maxVal = 1;
        for (int i = N - 1; i >= 0; i--) {
            maxVal = max(maxVal, vc[i]);
            ans += maxVal - vc[i];
        }

        cout << ans << "\n";
    }

    return 0;
}