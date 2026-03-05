#include <iostream>
#include <algorithm>
using namespace std;

int N, M, R;
int arr[301][301];
int r_move[4] = { 0, 1, 0, -1 };
int c_move[4] = { 1, 0, -1, 0 };

void rotate(int box) {
    for (int i = 0; i < box; i++) {
        int start = arr[i][i];
        int r = i;
        int c = i;

        int d = 0;
        while (d < 4) {
            int r_next = r + r_move[d];
            int c_next = c + c_move[d];

            if (r_next == i && c_next == i) {
                break;
            }

            if (r_next >= i && r_next < N - i && c_next >= i && c_next < M - i) {
                arr[r][c] = arr[r_next][c_next];
                r = r_next;
                c = c_next;
            }
            else {
                d += 1;
            }
        }

        arr[i + 1][i] = start;
    }
}

int main() {
    cin >> N >> M >> R;
    for (int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> arr[i][j];
        }
    }

    int cnt = min(N, M) / 2;
    for (int i = 0; i < R; i++) {
        rotate(cnt);
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << arr[i][j] << ' ';
        }

        cout << "\n";
    }

    return 0;
}