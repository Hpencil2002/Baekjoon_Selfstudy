#include <iostream>
#include <string>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int r, c;
        int ans = 0;

        cin >> r >> c;
        string candy[400];
        for (int i = 0; i < r; i++) {
            cin >> candy[i];
        }

        for (int i = 0; i < r; i++) {
            for (int j = 0; j + 2 < c; j++) {
                if (candy[i][j] == '>' && candy[i][j + 1] == 'o' && candy[i][j + 2] == '<') {
                    ans += 1;
                }
            }
        }

        for (int j = 0; j < c; j++) {
            for (int i = 0; i + 2 < r; i++) {
                if (candy[i][j] == 'v' && candy[i + 1][j] == 'o' && candy[i + 2][j] == '^') {
                    ans += 1;
                }
            }
        }

        cout << ans << "\n";
    }

    return 0;
}