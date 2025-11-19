#include <iostream>
using namespace std;

int ans;
int arr[5][5];
bool visit[1000000];
int x_move[4] = { 0, 0, 1, -1 };
int y_move[4] = { 1, -1, 0, 0 };

void dfs(int x, int y, int sum, int cnt) {
    if (cnt == 5) {
        if (visit[sum] == false) {
            visit[sum] = true;
            ans += 1;
        }

        return;
    }

    for (int i = 0; i < 4; i++) {
        int x_next = x + x_move[i];
        int y_next = y + y_move[i];

        if (x_next >= 0 && x_next < 5 && y_next >= 0 && y_next < 5) {
            dfs(x_next, y_next, sum * 10 + arr[x_next][y_next], cnt + 1);
        }
    }
}

int main() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            dfs(i, j, arr[i][j], 0);
        }
    }

    cout << ans;

    return 0;
}