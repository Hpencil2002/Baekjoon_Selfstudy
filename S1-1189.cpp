#include <iostream>
#include <queue>
using namespace std;

int R, C, K;
int ans;
char arr[6][6];
bool visit[6][6];
int x_move[4] = { 0, 0, 1, -1 };
int y_move[4] = { 1, -1, 0, 0 };

void dfs(int x, int y, int dis) {
    if (dis == K && x == 0 && y == C - 1) {
        ans += 1;

        return;
    }

    for (int d = 0; d < 4; d++) {
        int x_next = x + x_move[d];
        int y_next = y + y_move[d];

        if (arr[x_next][y_next] == 'T') {
            continue;
        }
        if (x_next < 0 || x_next >= R || y_next < 0 || y_next >= C) {
            continue;
        }
        if (visit[x_next][y_next]) {
            continue;
        }

        visit[x_next][y_next] = true;
        dfs(x_next, y_next, dis + 1);
        visit[x_next][y_next] = false;
    }
}

int main() {
    cin >> R >> C >> K;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> arr[i][j];
        }
    }

    visit[R - 1][0] = true;
    dfs(R - 1, 0, 1);

    cout << ans;

    return 0;
}