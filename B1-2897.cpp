#include <iostream>
#include <string>
using namespace std;

int main() {
    int R, C;
    cin >> R >> C;

    string str[50];
    for (int i = 0; i < R; i++) {
        cin >> str[i];
    }

    int ans[5] = { 0, };
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (i < R - 1 && j < C - 1) {
                int tmp = 0;

                if (str[i][j] == '#' || str[i + 1][j] == '#' || str[i][j + 1] == '#' || str[i + 1][j + 1] == '#') {
                    continue;
                }

                if (str[i][j] == 'X') {
                    tmp += 1;
                }
                if (str[i + 1][j] == 'X') {
                    tmp += 1;
                }
                if (str[i][j + 1] == 'X') {
                    tmp += 1;
                }
                if (str[i + 1][j + 1] == 'X') {
                    tmp += 1;
                }

                ans[tmp] += 1;
            }
        }
    }

    for (int i = 0; i < 5; i++) {
        cout << ans[i] << "\n";
    }

    return 0;
}