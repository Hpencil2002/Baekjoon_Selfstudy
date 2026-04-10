#include <iostream>
using namespace std;

int N;

int main() {
    int T;
    cin >> T;

    while (T--) {
        cin >> N;
        if (N < 10) {
            cout << "1\n";

            continue;
        }

        int ans = 0;
        while (true) {
            bool flag = false;

            for (int i = 9; i >= 2; i--) {
                if (N % i == 0) {
                    N /= i;
                    ans += 1;
                    flag = true;

                    break;
                }
            }

            if (N < 10) {
                ans += 1;

                break;
            }
            if (!flag) {
                ans = -1;

                break;
            }
        }

        cout << ans << "\n";
    }

    return 0;
}