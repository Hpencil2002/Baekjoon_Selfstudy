#include <iostream>
using namespace std;

int N;
int ans;

int main() {
    cin >> N;
    ans = N - 1;

    for (int i = 2; i * i <= N; i++) {
        if (N % i) {
            continue;
        }

        ans = N - N / i;
        break;
    }

    cout << ans;

    return 0;
}