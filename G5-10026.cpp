#include <iostream>
#include <cstring>
using namespace std;

int N, ans = 0;
char pic[101][101];
string input;
bool visited[101][101];

int x_move[4] = {1, -1, 0, 0};
int y_move[4] = {0, 0, 1, -1};

void dfs(int x, int y) {
    if (visited[x][y]) {
        return;
    }

    visited[x][y] = true;

    for (int i = 0; i < 4; i++) {
        int x_next = x + x_move[i];
        int y_next = y + y_move[i];

        if ((pic[x][y] == pic[x_next][y_next]) && !visited[x_next][y_next]) {
            dfs(x_next, y_next);
        }
    }
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> input;
        for (int j = 0; j < N; j++) {
            pic[i][j] = input[j];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!visited[i][j]) {
                dfs(i, j);
                ans += 1;
            }
        }
    }
    cout << ans << ' ';

    ans = 0;
    memset(visited, false, sizeof(visited));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (pic[i][j] == 'G') {
                pic[i][j] = 'R';
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!visited[i][j]) {
                dfs(i, j);
                ans += 1;
            }
        }
    }
    cout << ans;

    return 0;
}