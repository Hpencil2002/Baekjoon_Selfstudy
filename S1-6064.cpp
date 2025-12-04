#include <iostream>
using namespace std;

int M, N, x, y;

int main() {
    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        cin >> M >> N >> x >> y;

        int rx, ry;
        if (x > y) {
            rx = x - y + 1;
            ry = 1;
        }
        else {
            rx = 1;
            ry = y - x + 1;
        }

        int cnt = 1;
        int x_next = 1;
        int y_next = 1;
        bool stop = false;

        while (!stop) {
            if (x_next == rx && y_next == ry) {
                cnt += x - rx;
                x_next = x;
                y_next = y;
                stop = true;
            }
            else if (M - x_next < N - y_next) {
                y_next += M - x_next + 1;
                cnt += M - x_next + 1;
                x_next = 1;
            }
            else if (M - x_next > N - y_next) {
                x_next += N - y_next + 1;
                cnt += N - y_next + 1;
                y_next = 1;
            }
            else {
                cnt += N - y_next;
                x_next = M;
                y_next = N;
                stop = true;
            }
        }

        if (x_next == x && y_next == y) {
            cout << cnt << "\n";
        }
        else {
            cout << "-1\n";
        }
    }

    return 0;
}