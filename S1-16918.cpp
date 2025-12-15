#include <iostream>
#include <vector>
using namespace std;

int R, C, N;
char arr[201][201];
int boom[201][201];
int x_move[4] = { 0, 0, 1, -1 };
int y_move[4] = { 1, -1, 0, 0 };

void Install(int T) {
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (arr[i][j] == 'O') {
                continue;
            }

            arr[i][j] = 'O';
            boom[i][j] = T + 3;
        }
    }
}

void Delete(int T) {
    for (int x = 0; x < R; x++) {
        for (int y = 0; y < C; y++) {
            if (boom[x][y] == T) {
                for (int d = 0; d < 4; d++) {
                    int x_next = x + x_move[d];
                    int y_next = y + y_move[d];

                    if (x_next < 0 || x_next >= R || y_next < 0 || y_next >= C) {
                        continue;
                    }
                    if (arr[x_next][y_next] == '.') {
                        continue;
                    }

                    arr[x_next][y_next] = '.';
                }

                arr[x][y] = '.';
                boom[x][y] = 0;
            }
        }
    }
}

int main() {
    cin >> R >> C >> N;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> arr[i][j];

            if (arr[i][j] == 'O') {
                boom[i][j] = 3;
            }
        }
    }

    int Time = 2;
    while (true) {
        if (Time == N + 1) {
            break;
        }

        if (Time % 2 == 0) {
            Install(Time);
        }
        else {
            Delete(Time);
        }

        Time += 1;
    }

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cout << arr[i][j];
        }

        cout << "\n";
    }

    return 0;
}