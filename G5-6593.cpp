#include <iostream>
#include <string>
#include <queue>
#include <cstring>
using namespace std;

int L, R, C;
char arr[31][31][31];
bool visit[31][31][31];
string ans;
pair<pair<int, int>, int> Start, End;
int x_move[6] = { 0, 0, 1, -1, 0, 0 };
int y_move[6] = { 1, -1, 0, 0, 0, 0 };
int z_move[6] = { 0, 0, 0, 0, 1, -1 };

int bfs(int a, int b, int c) {
    queue<pair<pair<int, int>, pair<int, int>>> qu;
    qu.push({ { a, b }, { c, 0 }});
    visit[a][b][c] = true;

    while (!qu.empty()) {
        int z = qu.front().first.first;
        int x = qu.front().first.second;
        int y = qu.front().second.first;
        int res = qu.front().second.second;
        qu.pop();

        if (z == End.first.first && x == End.first.second && y == End.second) {
            return res;
        }

        for (int d = 0; d < 6; d++) {
            int z_next = z + z_move[d];
            int x_next = x + x_move[d];
            int y_next = y + y_move[d];

            if (z_next >= 0 && z_next < L && x_next >= 0 && x_next < R && y_next >= 0 && y_next < C) {
                if (arr[z_next][x_next][y_next] == '#') {
                    continue;
                }

                if (arr[z_next][x_next][y_next] == '.' || arr[z_next][x_next][y_next] == 'E') {
                    if (!visit[z_next][x_next][y_next]) {
                        visit[z_next][x_next][y_next] = true;
                        qu.push({ { z_next, x_next }, { y_next, res + 1 }});
                    }
                }
            }
        }
    }

    return -1;
}

int main() {
    while (true) {
        memset(visit, false, sizeof(visit));
        ans.clear();

        cin >> L >> R >> C;
        if (L == 0 && R == 0 && C == 0) {
            break;
        }

        for (int i = 0; i < L; i++) {
            for (int j = 0; j < R; j++) {
                for (int k = 0; k < C; k++) {
                    cin >> arr[i][j][k];

                    if (arr[i][j][k] == 'S') {
                        Start.first.first = i;
                        Start.first.second = j;
                        Start.second = k;
                    }
                    else if (arr[i][j][k] == 'E') {
                        End.first.first = i;
                        End.first.second = j;
                        End.second = k;
                    }
                }
            }
        }

        int check = bfs(Start.first.first, Start.first.second, Start.second);
        if (check == -1) {
            cout << "Trapped!\n";
        }
        else {
            cout << "Escaped in " << check << " minute(s).\n";
        }
    }

    return 0;
}