#include <iostream>
using namespace std;

int main() {
    int N, L, D;
    cin >> N >> L >> D;

    int time = 0;
    int ans = 0;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= L; j++) {
            time += 1;
        }

        for (int t = 1; t <= 5; t++) {
            if (time % D == 0) {
                ans = time;
                i = N;
                break;
            }

            time += 1;
        }

        if (i == N && ans == 0) {
            while (true) {
                if (time % D == 0) {
                    ans = time;
                    break;
                }

                time += 1;
            }
        }
    }

    cout << ans;

    return 0;
}