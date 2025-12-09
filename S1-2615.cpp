#include <iostream>
#include <vector>
using namespace std;

int arr[19][19];
vector<int> x_move[4] = { { 0, 0 }, { -1, 1 }, { -1, 1 }, { 1, -1 } };
vector<int> y_move[4] = { { -1, 1 }, { 0, 0 }, { 1, -1 }, { 1, -1 } };

int solve(int x, int y, int dir1, int dir2, int cnt) {
    if (cnt > 5) {
        return 999;
    }

    int x_next = x + x_move[dir1][dir2];
    int y_next = y + y_move[dir1][dir2];

    if (x_next < 0 || x_next >= 19 || y_next < 0 || y_next >= 19) {
        return cnt;
    }

    if (arr[x_next][y_next] == arr[x][y]) {
        cnt = solve(x_next, y_next, dir1, dir2, cnt + 1);
    }

    return cnt;
}

int init(int x, int y) {
    int ans = 0;

    for (int i = 0; i < 4; i++) {
        int val = 1;

        for (int j = 0; j < 2; j++) {
            int x_next = x + x_move[i][j];
            int y_next = y + y_move[i][j];

            if (x_next < 0 || x_next >= 19 || y_next < 0 || y_next >= 19) {
                continue;
            }

            if (arr[x][y] == arr[x_next][y_next]) {
                val += solve(x_next, y_next, i, j, 1);
            }
        }

        if (val == 5) {
            ans = arr[x][y];
            break;
        }
    }

    return ans;
}

int main() {
    int ans = 0;
    int ansX = 99, ansY = 99;

    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 19; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 19; j++) {
            if (arr[i][j] != 0) {
                int val = init(i, j);

                if (val != 0) {
                    if (j < ansY) {
                        ans = val;
                        ansX = i;
                        ansY = j;
                    }
                }
            }
        }
    }

    if (ans) {
        cout << ans << "\n";
        cout << ansX + 1 << ' ' << ansY + 1;
    }
    else {
        cout << 0;
    }

    return 0;
}