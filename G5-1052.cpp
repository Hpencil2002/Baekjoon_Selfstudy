#include <iostream>
using namespace std;

int N, K;
int ans;

int main() {
    cin >> N >> K;

    if (K >= N) {
        cout << ans;
    }
    else {
        while (true) {
            int cnt = 0;
            int tmp = N;

            while (tmp > 0) {
                if (tmp % 2 == 0) {
                    tmp /= 2;
                }
                else {
                    tmp /= 2;
                    cnt += 1;
                }
            }

            if (K >= cnt) {
                break;
            }

            N += 1;
            ans += 1;
        }

        cout << ans;
    }

    return 0;
}