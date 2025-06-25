#include <iostream>
#include <queue>
using namespace std;

int N;
int mp[101][101];

int main() {
    cin >> N;

    char k;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> k;

            if (k == '.') {
                mp[i][j] = 1;
            }
            else {
                mp[i][j] = 0;
            }
        }
    }

    int cnt_hor = 0;
    int hor = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (mp[i][j] == 1) {
                cnt_hor += 1;
            }
            else {
                cnt_hor = 0;
            }

            if (cnt_hor == 2) {
                hor += 1;
            }
        }

        cnt_hor = 0;
    }

    int cnt_ver = 0;
    int ver = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (mp[j][i] == 1) {
                cnt_ver += 1;
            }
            else {
                cnt_ver = 0;
            }

            if (cnt_ver == 2) {
                ver += 1;
            }
        }

        cnt_ver = 0;
    }

    cout << hor << ' ' << ver;

    return 0;
}