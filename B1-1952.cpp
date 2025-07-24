#include <iostream>
#include <cstring>
using namespace std;

int mp[101][101];
int dr[4] = { 0, 1, 0, -1 };
int dc[4] = { 1, 0, -1, 0 };

int main() {
    int M, N;
    cin >> M >> N;

    memset(mp, 0, sizeof(mp));
    int ans = 0;
    int cnt = 1;

    int d = 0;
    int r = 0;
    int c = 0;

    mp[r][c] = 1;
    while (true) {
        if (cnt == M * N) {
            break;
        }

        int nr = r + dr[d];
        int nc = c + dc[d];

        if (nr < 0 || nr > M - 1 || nc < 0 || nc > N - 1 || mp[nr][nc] == 1) {
            ans += 1;

            if (d == 3) {
                d = 0;
            }
            else {
                d += 1;
            }
        }
        else {
            mp[nr][nc] = 1;
            cnt += 1;
            r = nr;
            c = nc;
        }
    }

    cout << ans;

    return 0;
}