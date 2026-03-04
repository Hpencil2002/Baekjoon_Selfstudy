#include <iostream>
#include <vector>
using namespace std;

int N;
int ans;
int board[20][20];
int emptys[20][20];
int prefer[401][4];
int x_move[4] = { 0, 1, 0, -1 };
int y_move[4] = { 1, 0, -1, 0 };

void initEmpty() {
    emptys[0][0] = 2;
    emptys[0][N - 1] = 2;
    emptys[N - 1][0] = 2;
    emptys[N - 1][N - 1] = 2;

    for (int i = 1; i < N - 1; i++) {
        emptys[0][i] = 3;
        emptys[N - 1][i] = 3;
        emptys[i][0] = 3;
        emptys[i][N - 1] = 3;

        for (int j = 1; j < N - 1; j++) {
            emptys[i][j] = 4;
        }
    }
}

void findSeat(int student) {
    int Max = -1;
    int x, y, emptySeat;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j]) {
                continue;
            }

            int cnt = 0;
            for (int d = 0; d < 4; d++) {
                int x_next = j + x_move[d];
                int y_next = i + y_move[d];

                if (x_next < 0 || x_next >= N || y_next < 0 || y_next >= N) {
                    continue;
                }

                for (int k = 0; k < 4; k++) {
                    if (board[y_next][x_next] == prefer[student][k]) {
                        cnt += 1;

                        break;
                    }
                }
            }

            if (cnt > Max) {
                Max = cnt;
                x = j;
                y = i;
                emptySeat = emptys[y][x];
            }
            else if (cnt == Max) {
                if (emptys[i][j] > emptySeat) {
                    x = j;
                    y = i;
                    emptySeat = emptys[y][x];
                }
            }
        }
    }

    board[y][x] = student;
    for (int d = 0; d < 4; d++) {
        int x_next = x + x_move[d];
        int y_next = y + y_move[d];

        if (x_next < 0 || x_next >= N || y_next < 0 || y_next >= N) {
            continue;
        }

        emptys[y_next][x_next] -= 1;
    }
}

int main() {
    cin >> N;

    initEmpty();

    for (int i = 0; i < N * N; i++) {
        int student;
        cin >> student;

        for (int j = 0; j < 4; j++) {
            cin >> prefer[student][j];
        }

        findSeat(student);
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int cnt = 0;
            for (int d = 0; d < 4; d++) {
                int x_next = j + x_move[d];
                int y_next = i + y_move[d];

                if (x_next < 0 || x_next >= N || y_next < 0 || y_next >= N) {
                    continue;
                }

                for (int k = 0; k < 4; k++) {
                    if (board[y_next][x_next] == prefer[board[i][j]][k]) {
                        cnt += 1;

                        break;
                    }
                }
            }

            if (cnt == 1) {
                ans += 1;
            }
            else if (cnt == 2) {
                ans += 10;
            }
            else if (cnt == 3) {
                ans += 100;
            }
            else if (cnt == 4) {
                ans += 1000;
            }
        }
    }

    cout << ans;

    return 0;
}