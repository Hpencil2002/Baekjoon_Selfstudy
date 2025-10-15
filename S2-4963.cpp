#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int w, h;
int x_move[8] = { 1, 1, 0, -1, -1, -1, 0, 1 };
int y_move[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };
int map[50][50];
int visit[50][50];

void dfs(int y, int x) {
    for (int i = 0; i < 8; i++) {
        int dx = x + x_move[i];
        int dy = y + y_move[i];

        if (dx < 0 || dx >= w || dy < 0 || dy >= h) {
            continue;
        }

        if (!visit[dy][dx] && map[dy][dx]) {
            visit[dy][dx] = 1;
            dfs(dy, dx);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (true) {
        cin >> w >> h;
        if (w == 0 && h == 0) {
            return 0;
        }

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cin >> map[i][j];
            }
        }

        int ans = 0;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (!visit[i][j] && map[i][j]) {
                    visit[i][j] = 1;
                    dfs(i, j);
                    ans += 1;
                }
            }
        }

        cout << ans << "\n";
        memset(visit, 0, sizeof(visit));
    }
}