#include <iostream>
using namespace std;

int main() {
    int A, B, N;
    int ans = 0;
    cin >> A >> B >> N;

    if (A % B == 0) {
        cout << ans;
        return 0;
    }

    if (A > B) {
        A %= B;
    }

    for (int i = 0; i < N; i++) {
        A *= 10;
        ans = (int)(A / B);
        A %= B;
    }

    cout << ans;

    return 0;
}