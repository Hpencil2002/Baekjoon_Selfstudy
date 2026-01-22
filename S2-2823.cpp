#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef struct {
    int y;
    int x;
} Dir;

int R, C;
vector<string> vc;
Dir moveDir[4] = { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } };

int solve() {
    bool cycle = false;

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (vc[i][j] == 'X') {
                continue;
            }

            int cnt = 0;
            for (int d = 0; d < 4; d++) {
                int x_next = j + moveDir[d].x;
                int y_next = i + moveDir[d].y;

                if (x_next >= 0 && x_next < C && y_next >= 0 && y_next < R) {
                    if (vc[y_next][x_next] == '.') {
                        cnt += 1;
                    }
                }
            }

            if (cnt <= 1) {
                cycle = true;

                break;
            }
        }
    }

    return cycle ? 1 : 0;
}

int main() {
    cin >> R >> C;

    vc.resize(R);
    for (int i = 0; i < R; i++) {
        cin >> vc[i];
    }

    cout << solve();

    return 0;
}