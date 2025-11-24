#include <iostream>
#include <algorithm>
using namespace std;

int N;
int ans = INT32_MAX;
int arr[10][10];
int visit[10][10];
int x_move[4] = { 0, 0, -1, 1 };
int y_move[4] = { -1, 1, 0, 0 };

void dfs(int sum, int cnt) {
    if (cnt == 3) {
        ans = min(ans, sum);
        return;
    }

    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            int check = 0;

            int x_next, y_next;
            for (int d = 0; d < 4; d++) {
                x_next = x + x_move[d];
                y_next = y + y_move[d];

                if (x_next < 0 || x_next >= N || y_next < 0 || y_next >= N) {
                    continue;
                }
                if (visit[y_next][x_next]) {
                    continue;
                }

                check += 1;
            }

            if (check == 4) {
                int curSum = arr[y][x];

                for (int d = 0; d < 4; d++) {
                    x_next = x + x_move[d];
                    y_next = y + y_move[d];
                    visit[y_next][x_next] = 1;
                    curSum += arr[y_next][x_next];
                }

                visit[y][x] = 1;
                sum += curSum;
                cnt += 1;

                dfs(sum, cnt);

                sum -= curSum;
                cnt -= 1;

                for (int d = 0; d < 4; d++) {
                    x_next = x + x_move[d];
                    y_next = y + y_move[d];
                    visit[y_next][x_next] = 0;
                }
                visit[y][x] = 0;
            }
        }
    }
}

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }

    dfs(0, 0);

    cout << ans;

    return 0;
}