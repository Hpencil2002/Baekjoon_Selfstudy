#include <iostream>
using namespace std;

int N, M, x, y;
int ans;
bool wall[101];

int main() {
    cin >> N >> M;

    for (int i = 0; i < N - 1; i++) {
        wall[i] = true;
    }

    while (M--) {
        cin >> x >> y;

        for (int i = x - 1; i < y - 1; i++) {
            wall[i] = false;
        }
    }

    for (int i = 0; i < N - 1; i++) {
        if (wall[i]) {
            ans += 1;
        }
    }

    cout << ans + 1;

    return 0;
}