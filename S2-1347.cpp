#include <iostream>
#include <vector>
using namespace std;

int N;
int arr[101][101];
vector<char> vc;
pair<int, int> start;
int x_move[4] = { 0, 0, 1, -1 };
int y_move[4] = { 1, -1, 0, 0 };

int change(int dir, char cmd) {
    if (cmd == 'R') {
        if (dir == 0) {
            return 2;
        }
        else if (dir == 1) {
            return 3;
        }
        else if (dir == 2) {
            return 1;
        }
        else if (dir == 3) {
            return 0;
        }
    }
    else if (cmd == 'L') {
        if (dir == 0) {
            return 3;
        }
        else if (dir == 1) {
            return 2;
        }
        else if (dir == 2) {
            return 0;
        }
        else if (dir == 3) {
            return 1;
        }
    }
}

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        char c;
        cin >> c;
        vc.push_back(c);
    }
    start.first = start.second = 50;

    int x = start.first;
    int y = start.second;
    int dir = 2;

    arr[x][y] = 1;
    for (int i = 0; i < N; i++) {
        char d = vc[i];
        if (d == 'R' || d == 'L') {
            dir = change(dir, d);
        }
        else if (d == 'F') {
            x = x + x_move[dir];
            y = y + y_move[dir];
            arr[x][y] = 1;
        }
    }

    int sx, sy, ex, ey;
    sx = sy = 101;
    ex = ey = 0;
    for (int i = 0; i < 101; i++) {
        for (int j = 0; j < 101; j++) {
            if (arr[i][j] == 1) {
                if (i < sx) {
                    sx = i;
                }
                if (i > ex) {
                    ex = i;
                }
                if (j < sy) {
                    sy = j;
                }
                if (j > ey) {
                    ey = j;
                }
            }
        }
    }

    for (int i = sx; i <= ex; i++) {
        for (int j = sy; j <= ey; j++) {
            if (arr[i][j] == 1) {
                cout << '.';
            }
            else {
                cout << '#';
            }
        }

        cout << "\n";
    }

    return 0;
}