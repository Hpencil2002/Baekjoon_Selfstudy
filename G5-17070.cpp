#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int arr[17][17];
int ans;
int r_move[3] = { 0, 1, 1 };
int c_move[3] = { 1, 0, 1 };

bool check(int r, int c) {
    if (r < 1 || r > N || c < 1 || c > N || arr[r][c] == 1) {
        return false;
    }

    return true;
}

void dfs(int r, int c, int dir) {
    if (r == N && c == N) {
        ans += 1;

        return;
    }

    for (int d = 0; d < 3; d++) {
        if ((dir == 0 && d == 1) || (dir == 1 && d == 0)) {
            continue;
        }

        int r_next = r + r_move[d];
        int c_next = c + c_move[d];

        if (!check(r_next, c_next)) {
            continue;
        }
        if (d == 2 && (arr[r + 1][c] == 1 || arr[r][c + 1] == 1)) {
            continue;
        }

        dfs(r_next, c_next, d);
    }
}

int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> arr[i][j];
        }
    }

    dfs(1, 2, 0);

    cout << ans;

    return 0;
}