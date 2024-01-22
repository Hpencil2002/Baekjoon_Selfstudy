#include <iostream>
#include <vector>
using namespace std;

int map[501][501];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m, b, height;
    int time = 2147000000;
    cin >> n >> m >> b;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }

    for (int k = 0; k <= 256; k++) {
        int sum = 0, tmp = b;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (map[i][j] < k) {
                    sum += k - map[i][j];
                    tmp -= k - map[i][j];
                }
                else if (map[i][j] > k) {
                    sum += (map[i][j] - k) * 2;
                    tmp += map[i][j] - k;
                }
                else {
                    continue;
                }
            }
        }

        if (tmp >= 0) {
            if (sum <= time) {
                time = sum;
                height = k;
            }
        }
    }

    cout << time << " " << height;

    return 0;
}