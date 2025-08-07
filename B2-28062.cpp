#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;

    int candy[1000] = { 0, };
    for (int i = 0; i < N; i++) {
        cin >> candy[i];
    }

    sort(candy, candy + N, greater<int>());

    int ans = 0;
    int odd = 0;
    for (int i = 0; i < N; i++) {
        if (candy[i] % 2 == 0) {
            ans += candy[i];
        }
        else {
            if (odd) {
                ans += odd + candy[i];
                odd = 0;
            }
            else {
                odd = candy[i];
            }
        }
    }

    cout << ans;

    return 0;
}