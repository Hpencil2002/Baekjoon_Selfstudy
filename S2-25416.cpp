#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int arr[5][5];
int r, c;
bool visit[5][5];
int r_move[4] = { 0, 1, 0, -1 };
int c_move[4] = { 1, 0, -1, 0 };

int bfs() {
    queue<pair<int, pair<int, int>>> qu;
    qu.push({ 0, { r, c }});
    visit[r][c] = true;

    while (!qu.empty()) {
        int r_cur = qu.front().second.first;
        int c_cur = qu.front().second.second;
        int res = qu.front().first;
        qu.pop();

        if (arr[r_cur][c_cur] == 1) {
            return res;
        }

        for (int d = 0; d < 4; d++) {
            int r_next = r_cur + r_move[d];
            int c_next = c_cur + c_move[d];

            if (r_next >= 0 && r_next < 5 && c_next >= 0 && c_next < 5) {
                if (!visit[r_next][c_next] && arr[r_next][c_next] != -1) {
                    visit[r_next][c_next] = true;
                    qu.push({ res + 1, { r_next, c_next }});
                }
            }
        }
    }

    return -1;
}

int main() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> arr[i][j];
        }
    }
    cin >> r >> c;

    cout << bfs();

    return 0;
}