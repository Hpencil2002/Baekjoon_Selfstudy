#include <iostream>
using namespace std;

int N, M;
int ans;
int arr[101][101];
int x_move[4] = { 0, 0, 1, -1 };
int y_move[4] = { 1, -1, 0, 0 };

int solve(int x, int y) {
    int cnt = 0;

    for (int d = 0; d < 4; d++) {
        int x_next = x + x_move[d];
        int y_next = y + y_move[d];

        if (x_next >= 0 && x_next < N && y_next >= 0 && y_next < M) {
            if (arr[x_next][y_next] < arr[x][y]) {
                cnt += (arr[x][y] - arr[x_next][y_next]);
            }
        }
        else {
            cnt += arr[x][y];
        }
    }

    return cnt;
}

int main() {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            ans += solve(i, j);
        }
    }
    ans += (N * M * 2);

    cout << ans;

    return 0;
}