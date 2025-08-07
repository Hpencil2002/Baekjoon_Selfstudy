#include <iostream>
using namespace std;

int main() {
    int A, B, C, M;
    cin >> A >> B >> C >> M;

    int ans = 0;
    int fatigue = 0;
    int n = 24;

    while (n--) {
        if (fatigue + A <= M) {
            ans += B;
            fatigue += A;
        }
        else {
            fatigue -= C;

            if (fatigue < 0) {
                fatigue = 0;
            }
        }
    }

    cout << ans;

    return 0;
}