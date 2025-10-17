#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int N;
    cin >> N;

    int ans = 0;
    for (int i = 0; i < N; i++) {
        int C, K;
        cin >> C >> K;
        ans += C * K;
    }

    cout << ans;

    return 0;
}