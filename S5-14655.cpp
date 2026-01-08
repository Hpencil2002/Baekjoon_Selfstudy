#include <iostream>
#include <algorithm>
using namespace std;

int N;
long long ans;

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        int coin;
        cin >> coin;

        ans += abs(coin);
    }

    for (int i = 0; i < N; i++) {
        int coin;
        cin >> coin;

        ans += abs(coin);
    }

    cout << ans;

    return 0;
}