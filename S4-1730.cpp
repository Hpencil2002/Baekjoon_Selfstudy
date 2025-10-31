#include <iostream>
#include <string>
using namespace std;

int N;
string M;
bool p[100][100];
bool h[100][100];
int row, col;

bool check(const int& row, const int& col) {
    if (row < 0 || row >= N || col < 0 || col >= N) {
        return false;
    }

    return true;
}

int main() {
    cin >> N >> M;

    for (int i = 0; i < M.size(); i++) {
        if (M[i] == 'U') {
            if (!check(row - 1, col)) {
                continue;
            }

            p[row][col] = true;
            p[--row][col] = true;
        }
        else if (M[i] == 'D') {
            if (!check(row + 1, col)) {
                continue;
            }

            p[row][col] = true;
            p[++row][col] = true;
        }
        else if (M[i] == 'L') {
            if (!check(row, col - 1)) {
                continue;
            }

            h[row][col] = true;
            h[row][--col] = true;
        }
        else {
            if (!check(row, col + 1)) {
                continue;
            }

            h[row][col] = true;
            h[row][++col] = true;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (p[i][j] && h[i][j]) {
                cout << '+';
            }
            else if (p[i][j]) {
                cout << '|';
            }
            else if (h[i][j]) {
                cout << '-';
            }
            else {
                cout << '.';
            }
        }

        cout << "\n";
    }

    return 0;
}