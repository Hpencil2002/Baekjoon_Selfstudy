#include <iostream>
using namespace std;

int score[101];

int main() {
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> score[i];
    }

    int ans = 0;
    for (int i = N -1; i >= 1; i--) {
        while (score[i] <= score[i - 1]) {
            score[i - 1] -= 1;
            ans += 1;
        }
    }

    cout << ans;

    return 0;
}