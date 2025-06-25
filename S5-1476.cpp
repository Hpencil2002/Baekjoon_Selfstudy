#include <iostream>
using namespace std;

int main() {
    int E, S, M;
    cin >> E >> S >> M;

    int ans = 1;
    while (true) {
        if ((ans - E) % 15 == 0 && (ans - S) % 28 == 0 && (ans - M) % 19 == 0) {
            break;
        }

        ans += 1;
    }

    cout << ans;

    return 0;
}