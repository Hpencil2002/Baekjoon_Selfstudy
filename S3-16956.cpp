#include <iostream>
#include <string>
#include <vector>
using namespace std;

int x_move[4] = { 0, 0, -1, 1 };
int y_move[4] = { 1, -1, 0, 0 };
vector<string> board;

int main() {
    int R, C;
    cin >> R >> C;

    board.resize(R);
    for (auto& x : board) {
        cin >> x;
    }

    bool flag = true;
    int x_next;
    int y_next;
    for (int y = 0; y < R; y++) {
        for (int x = 0; x < C; x++) {
            if (board[y][x] == 'W') {
                for (int i = 0; i < 4; i++) {
                    x_next = x + x_move[i];
                    y_next = y + y_move[i];

                    if (x_next >= 0 && x_next < C && y_next >= 0 && y_next < R) {
                        if (board[y_next][x_next] == 'S') {
                            flag = false;
                            goto END;
                        }
                        else {
                            if (board[y_next][x_next] == '.') {
                                board[y_next][x_next] = 'D';
                            }
                        }
                    }
                }
            }
        }
    }
END:
    cout << flag << "\n";
    if (flag) {
        for (const auto& x : board) {
            cout << x << "\n";
        }
    }

    return 0;
}