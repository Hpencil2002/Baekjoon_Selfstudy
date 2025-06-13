#include <iostream>
#include <algorithm>
using namespace std;

int T, n;
int ans = 0;
int score[2][100005] = {0, };

int main() {
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> n;

        for (int j = 0; j < 2; j++) {
            for (int k = 2; k <= n + 1; k++) {
                cin >> score[j][k];
            }
        }

        for (int j = 2; j <= n + 1; j++) {
            score[0][j] += max(score[1][j - 1], score[1][j - 2]);
            score[1][j] += max(score[0][j - 1], score[0][j - 2]);
        }

        ans = max(score[0][n + 1], score[1][n + 1]);
        cout << ans << "\n";
    }

    return 0;
}