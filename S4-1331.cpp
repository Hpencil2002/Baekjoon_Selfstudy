#include <iostream>
#include <string>
using namespace std;

bool flag;
int x_move[8] = { -2, -2, -1, -1, 1, 1, 2, 2 };
int y_move[8] = { -1, 1, -2, 2, -2, 2, -1, 1 };
int visited[6][6];

int main() {
    string str;
    cin >> str;

    int srow = 5 - (str[1] - '1');
    int scol = str[0] - 'A';
    int prow = srow;
    int pcol = scol;
    visited[prow][pcol] = 1;

    for (int i = 0; i < 35; i++) {
        cin >> str;

        int row = 5 - (str[1] - '1');
        int col = str[0] - 'A';
        flag = false;

        for (int j = 0; j < 8; j++) {
            int mx = prow + x_move[j];
            int my = pcol + y_move[j];

            if (mx < 0 || mx >= 6 || my < 0 || my >= 6) {
                continue;
            }
            if (mx == row && my == col && visited[mx][my] == 0) {
                visited[row][col] = 1;
                flag = true;
                break;
            }
        }

        if (flag) {
            prow = row;
            pcol = col;
        }
        else {
            cout << "Invalid";
            return 0;
        }
    }

    flag = false;
    for (int i = 0; i < 8; i++) {
        if (prow + x_move[i] == srow && pcol + y_move[i] == scol) {
            flag = true;
            break;
        }
    }

    if (flag) {
        cout << "Valid";
    }
    else {
        cout << "Invalid";
    }

    return 0;
}