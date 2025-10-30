#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int I[45][45];

int solve(int yy, int xx) {
    vector<int> vc;

    for (int y = 0; y <= 2; y++) {
        for (int x = 0; x <= 2; x++) {
            vc.push_back(I[yy + y][xx + x]);
        }
    }

    sort(vc.begin(), vc.end());

    return vc[4];
}

int main() {
    int R, C;
    cin >> R >> C;

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> I[i][j];
        }
    }

    int T;
    cin >> T;

    int ans = 0;
    vector<int> vc;
    for (int i = 0; i < R - 2; i++) {
        for (int j = 0; j < C - 2; j++) {
            int res = solve(i, j);
            ans += (res >= T);
        }
    }

    cout << ans;

    return 0;
}