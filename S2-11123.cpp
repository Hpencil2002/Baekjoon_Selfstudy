#include <iostream>
using namespace std;

int H, W;

int arr[101][101];
bool visit[101][101];
int x_move[4] = { -1, 1, 0, 0 };
int y_move[4] = { 0, 0, -1, 1 };
int ans[101];
int cnt = 0;

void dfs(int y, int x) {
    visit[y][x] = true;

    for (int d = 0; d < 4; d++) {
        int x_next = x + x_move[d];
        int y_next = y + y_move[d];

        if (x_next < 0 || x_next >= W || y_next < 0 || y_next >= H) {
            continue;
        }

        if (arr[y_next][x_next] == 1 && !visit[y_next][x_next]) {
            dfs(y_next, x_next);
        }
    }
}

void reset() {
    for (int i = 0; i < 101; i++) {
        for (int j = 0; j < 101; j++) {
            arr[i][j] = 0;
            visit[i][j] = false;
        }
    }

    cnt = 0;
}

int main() {
    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        cin >> H >> W;

        char input[101][101];
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                cin >> input[i][j];

                if (input[i][j] == '.') {
                    arr[i][j] = 0;
                }
                if (input[i][j] == '#') {
                    arr[i][j] = 1;
                }
            }
        }

        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                if (arr[i][j] == 1 && !visit[i][j]) {
                    dfs(i, j);
                    cnt += 1;
                }
            }
        }
        ans[t] = cnt;

        reset();
    }

    for (int i = 0; i < T; i++) {
        cout << ans[i] << "\n";
    }

    return 0;
}