#include <iostream>
using namespace std;

int main() {
    int N;
    int ans = 0;

    cin >> N;
    for (int i = 1; i < N; i++) {
        for (int j = i; j < N; j++) {
            int k = N - i - j;

            if (j > k) {
                break;
            }
            if (i + j > k) {
                ans += 1;
            }
        }
    }

    cout << ans;

    return 0;
}