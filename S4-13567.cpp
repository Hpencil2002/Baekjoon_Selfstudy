#include <iostream>
#include <string>
using namespace std;

int x_move[4] = { 0, 1, 0, -1 };
int y_move[4] = { 1, 0, -1, 0 };

int main() {
    int M, n;
    cin >> M >> n;

    int x = 0, y = 0;
    int dir = 0;
    while (n--) {
        string str;
        int d;
        cin >> str >> d;

        if (str == "MOVE") {
            for (int i = 0; i < d; i++) {
                x += x_move[dir];
                y += y_move[dir];
            }

            if (x < 0 || x >= M || y < 0 || y >= M) {
                cout << -1;

                return 0;
            }
        }
        else {
            if (d == 0) {
                dir = (dir + 1) % 4;
            }
            else {
                dir = (dir + 3) % 4;
            }
        }
    }

    cout << y << ' ' << x;

    return 0;
}