#include <iostream>
using namespace std;

int board[101][101] = { 0, };
int x_move[4] = { 0, 1, 0, -1 };
int y_move[4] = { 1, 0, -1, 0 };

int main() {
    int N;
    cin >> N;

    int row, col;
    for (int i = 0; i < N; i++) {
        cin >> row >> col;

        for (int r = row; r < row + 10; r++) {
            for (int c = col; c < col + 10; c++) {
                board[r][c] = 1;
            }
        }
    }

    int ans = 0;
    for (int r = 1; r < 101; r++) {
        for (int c = 1; c < 101; c++) {
            if (board[r][c] == 1) {
                for (int i = 0; i < 4; i++) {
                    if (board[r + y_move[i]][c + x_move[i]] == 0) {
                        ans += 1;
                    }
                }
            }
        }
    }

    cout << ans;

    return 0;
}