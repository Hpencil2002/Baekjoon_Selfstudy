#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    vector<int> H = vector<int>(N);
    for (int i = 0; i < N; i++) {
        cin >> H[i];
    }

    int ans = 1;
    for (int i = N - 1; i > 0; i--) {
        if (H[i] >= H[i - 1]) {
            ans += 1;
        }
    }

    cout << ans;

    return 0;
}