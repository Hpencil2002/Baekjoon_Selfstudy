#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    int ans = 0;
    for (int i = 1; i < N + 1; i++) {
        if (i * i > N) {
            break;
        }

        ans += 1;
    }

    cout << ans;

    return 0;
}