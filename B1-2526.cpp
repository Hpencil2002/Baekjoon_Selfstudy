#include <iostream>
using namespace std;

int ans;
int cnt[98];

int main() {
    int N, P;
    cin >> N >> P;

    int tmp = N;
    while (true) {
        tmp = (tmp * N) % P;

        if (cnt[tmp] == 2) {
            break;
        }

        cnt[tmp] += 1;
    }

    for (int i = 0; i < P; i++) {
        if (cnt[i] == 2) {
            ans += 1;
        }
    }

    cout << ans;

    return 0;
}