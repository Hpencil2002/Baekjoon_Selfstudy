#include <iostream>
using namespace std;

int N, M;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        cin >> N >> M;

        long long ans = 1;
        int k = 1;
        for (int j = M; j > M - N; j--) {
            ans *= j;
            ans /= k;
            k += 1;
        }

        cout << ans << "\n";
    }

    return 0;
}