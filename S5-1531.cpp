#include <iostream>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    int x1, y1, x2, y2, ans = 0;
    int arr[101][101] = { 0, };

    for (int i = 0; i < N; i++) {
        cin >> x1 >> y1 >> x2 >> y2;

        for (int x = x1; x <= x2; x++) {
            for (int y = y1; y <= y2; y++) {
                arr[x][y] += 1;
            }
        }
    }

    for (int i = 1; i <= 100; i++) {
        for (int j = 1; j <= 100; j++) {
            if (arr[i][j] > M) {
                ans += 1;
            }
        }
    }

    cout << ans;

    return 0;
}