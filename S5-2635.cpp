#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int connectNum(int n, int i) {
    int cnt = 0;

    while (n >= 0) {
        i = n - i;
        n -= i;
        cnt += 1;
    }

    return cnt;
}

int main() {
    int N;
    cin >> N;

    int cnt = 0;
    int index = 0;
    for (int i = 0; i <= N / 2 + 1; i++) {
        if (cnt < connectNum(N, N - i)) {
            index = N - i;
        }

        cnt = max(cnt, connectNum(N, N - i));
    }

    cout << cnt << "\n";

    while (N >= 0) {
        cout << N << ' ';
        index = N - index;
        N -= index;
    }

    return 0;
}