#include <iostream>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    int arr[301][301];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i + 1][j + 1];
        }
    }

    int K;
    cin >> K;
    while (K--) {
        int i, j, x, y, sum = 0;
        cin >> i >> j >> x >> y;

        for (int n = i; n <= x; n++) {
            for (int m = j; m <= y; m++) {
                sum += arr[n][m];
            }
        }

        cout << sum << "\n";
    }

    return 0;
}