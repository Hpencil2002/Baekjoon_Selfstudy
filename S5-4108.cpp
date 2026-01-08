#include <iostream>
using namespace std;

int R, C;
char arr[101][101];
char ans[101][101];

char getMine(int start, int end) {
    int cnt = 0;

    for (int i = start - 1; i <= start + 1; i++) {
        for (int j = end - 1; j <= end + 1; j++) {
            if (i < 0 || i >= R || j < 0 || j >= C) {
                continue;
            }

            if (arr[i][j] == '*') {
                cnt += 1;
            }
        }
    }

    return cnt + '0';
}

int main() {
    while (true) {
        cin >> R >> C;
        if (R == 0 && C == 0) {
            return 0;
        }

        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                cin >> arr[i][j];
            }
        }

        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (arr[i][j] == '*') {
                    ans[i][j] = '*';
                    continue;
                }

                ans[i][j] = getMine(i, j);
            }
        }

        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                cout << ans[i][j];
            }

            cout << "\n";
        }
    }
}