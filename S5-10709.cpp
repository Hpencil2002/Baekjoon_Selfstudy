#include <iostream>
#include <string>
using namespace std;

string cloud[101];
int ans[101][101];

int main() {
    int H, W;
    cin >> H >> W;

    for (int i = 0; i < H; i++) {
        cin >> cloud[i];
    }

    for (int i = 0; i < H; i++) {
        int tmp = -1;

        for (int j = 0; j < W; j++) {
            if (cloud[i][j] == 'c') {
                ans[i][j] = 0;
                tmp = 0;
            }
            else {
                if (tmp != -1) {
                    tmp += 1;
                }

                ans[i][j] = tmp;
            }
        }
    }

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cout << ans[i][j] << ' ';
        }

        cout << "\n";
    }

    return 0;
}