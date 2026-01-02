#include <iostream>
using namespace std;

int N;
int ans = 2;

int main() {
    cin >> N;

    if (N == 1) {
        cout << 0;
    }
    else if (N == 2) {
        cout << 2;
    }
    else {
        for (int i = 0; i < N - 2; i++) {
            ans *= 3;
        }

        cout << ans;
    }

    return 0;
}