#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int ans = -1;
int num[500][500];
int visited[500][500];
int x_move[4] = {0, 1, 0, -1};
int y_move[4] = {1, 0, -1, 0};

void dfs(int y, int x, int d, int sum) {
    sum += num[y][x];
    visited[y][x] = 1;

    if (d == 4) {
        if (sum > ans) {
            ans = sum;
        }
        visited[y][x] = 0;
        return;
    }

    for (int i = 0; i < 4; i++) {
        int x_next = x + x_move[i];
        int y_next = y + y_move[i];

        if (x_next >= 0 && x_next < M && y_next >= 0 && y_next < N) {
            if (!visited[y_next][x_next]) {
                dfs(y_next, x_next, d + 1, sum);
            }
        }
    }
    visited[y][x] = 0;
}

void T(int y, int x) {
    int sum, x_next, y_next;

    for (int i = 0; i < 4; i++) {
        sum = num[y][x];

        for (int j = 0; j < 4; j++) {
            if (j == i) {
                continue;
            }

            x_next = x + x_move[j];
            y_next = y + y_move[j];

            if (x_next >= 0 && x_next < M && y_next >= 0 && y_next < N) {
                sum += num[y_next][x_next];
            }
        }

        if (sum > ans) {
            ans = sum;
        }
    }
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> num[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            dfs(i, j, 1, 0);
            T(i, j);
        }
    }

    cout << ans;

    return 0;
}