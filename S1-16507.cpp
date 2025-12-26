#include <iostream>
using namespace std;

int R, C, K;
int r1, c1, r2, c2;
int arr[1001][1001] = { 0, };

int main() {
    cin >> R >> C >> K;
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            cin >> arr[i][j];

            arr[i][j] += arr[i - 1][j] + arr[i][j - 1] - arr[i - 1][j - 1];
        }
    }

    for (int i = 0; i < K; i++) {
        cin >> r1 >> c1 >> r2 >> c2;

        int s = arr[r2][c2] - arr[r1 - 1][c2] - arr[r2][c1 - 1] + arr[r1 - 1][c1 - 1];
        int z = (r2 - r1 + 1) * (c2 - c1 + 1);

        cout << s / z << "\n";
    }

    return 0;
}