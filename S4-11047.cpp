#include <iostream>
using namespace std;

int N, K;
int coin[10];
int ans = 0;

int main() {
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> coin[i];
    }

    for (int i = N - 1; i >= 0; i--) {
        if (coin[i] > K) {
            continue;
        }
        else {
            ans += K / coin[i];
            K %= coin[i];
        }

        if (K == 0) {
            break;
        }
    }

    cout << ans;

    return 0;
}