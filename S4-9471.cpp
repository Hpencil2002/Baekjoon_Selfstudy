#include <iostream>
using namespace std;

int solve(int M) {
    int prev = 1;
    int cur = 1;
    int tmp;

    for (int i = 0; i < M * M; i++) {
        tmp = (prev + cur) % M;
        prev = cur;
        cur = tmp;

        if (prev == 1 && cur == 1) {
            return i + 1;
        }
    }

    return 0;
}

int main() {
    int P;
    cin >> P;

    while (P--) {
        int N, M;
        cin >> N >> M;

        cout << N << ' ' << solve(M) << "\n";
    }

    return 0;
}