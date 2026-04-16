#include <iostream>
using namespace std;

long long N;
long long ans;

int main() {
    cin >> N;
    while (N % 5) {
        N -= 3;
        ans += 1;
    }

    if (N < 0) {
        cout << -1;
    }
    else {
        cout << ans + N / 5;
    }

    return 0;
}