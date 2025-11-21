#include <iostream>
using namespace std;

int N;
long long ans;

int main() {
    cin >> N;

    for (int i = 1; i <= N; i++) {
        ans += (N / i) * i;
    }

    cout << ans;

    return 0;
}