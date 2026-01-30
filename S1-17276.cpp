#include <iostream>
#include <vector>
#include <deque>
#include <cstring>
#include <algorithm>
using namespace std;

int n, d;
int arr[501][501];

int main() {
    int T;
    cin >> T;

    while (T--) {
        cin >> n >> d;

        vector<int> dir[4];
        deque<vector<int>> order;

        memset(arr, 0, sizeof(arr));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> arr[i][j];

                if (i == n / 2) {
                    dir[0].push_back(arr[i][j]);
                }
                if (j == i) {
                    dir[1].push_back(arr[i][j]);
                }
                if (j == n / 2) {
                    dir[2].push_back(arr[i][j]);
                }
                if (j == (n - 1) - i) {
                    dir[3].push_back(arr[i][j]);
                }
            }
        }

        for (auto it : dir) {
            order.push_back(it);
        }

        int cnt = (d >= 0) ? d / 45 : d / 45 * (-1);
        while (cnt--) {
            vector<int> vc;

            if (d < 0) {
                vc = order.front();
                reverse(vc.begin(), vc.end());
                order.pop_front();
                order.push_back(vc);
            }
            else if (d > 0) {
                vc = order.back();
                reverse(vc.begin(), vc.end());
                order.pop_back();
                order.push_front(vc);
            }
        }

        int k = 0;
        while (!order.empty()) {
            dir[k] = order.front();
            order.pop_front();
            k += 1;
        }

        int x = n / 2;
        int y = n / 2;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < dir[i].size(); j++) {
                if (i == 0) {
                    arr[x][j] = dir[i][j];
                }
                else if (i == 1) {
                    arr[j][j] = dir[i][j];
                }
                else if (i == 2) {
                    arr[j][y] = dir[i][j];
                }
                else if (i == 3) {
                    arr[j][n - 1 - j] = dir[i][j];
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << arr[i][j] << ' ';
            }

            cout << "\n";
        }
    }

    return 0;
}