#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int K, C;
    cin >> K >> C;

    for (int i = 0; i < C; i++) {
        int M, N;
        cin >> M >> N;

        if (M == N) {
            cout << "1\n";

            continue;
        }

        int remain = K - max(M, N);
        int diff = abs(M - N);

        if (M > N) {
            if (diff - remain <= 2) {
                cout << "1\n";

                continue;
            }

            cout << "0\n";

            continue;
        }

        if (diff - remain <= 1) {
            cout << "1\n";

            continue;
        }

        cout << "0\n";
    }

    return 0;
}