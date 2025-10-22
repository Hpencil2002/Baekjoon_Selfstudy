#include <iostream>
using namespace std;

int x_move[8] = { 1, -1, 0, 0, 1, 1, -1, -1 };
int y_move[8] = { 0, 0, 1, -1, 1, -1, 1, -1 };
char arr[11][11];
char newarr[11][11];

void check(int y, int x) {
    int bomb = 0;

    for (int i = 0; i < 8; i++) {
        int y_next = y + y_move[i];
        int x_next = x + x_move[i];

        if (arr[y_next][x_next] == '*') {
            bomb += 1;
        }
    }

    char tmp = '0';
    newarr[y][x] = tmp + bomb;
}

int main() {
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
            newarr[i][j] = '.';
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            char c;
            cin >> c;

            if (c == 'x' && arr[i][j] == '.') {
                check(i, j);
            }
            else if (c == 'x' && arr[i][j] == '*') {
                for (int y = 0; y < N; y++) {
                    for (int x = 0; x < N; x++) {
                        if (arr[y][x] == '*') {
                            newarr[y][x] = '*';
                        }
                    }
                }
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << newarr[i][j];
        }

        cout << "\n";
    }

    return 0;
}