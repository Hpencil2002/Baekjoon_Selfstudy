#include <iostream>
using namespace std;

int main() {
    int L, P, V;

    int cnt = 1;
    while (true) {
        cin >> L >> P >> V;

        if (L == 0 && P == 0 && V == 0) {
            return 0;
        }

        int use = V / P;
        int left = V % P;
        if (L < left) {
            left = L;
        }

        int ans = L * use + left;

        cout << "Case " << cnt << ": " << ans << "\n";
        cnt += 1;
    }
}