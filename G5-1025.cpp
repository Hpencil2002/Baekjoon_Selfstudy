#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

int N, M;

bool check(int n) {
    return sqrt(n) == (int)sqrt(n);
}

int solve(char arr[][10], int n, int m) {
    int res = -1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int dx = -n; dx < n; dx++) {
                for (int dy = -m; dy < m; dy++) {
                    if (dx == 0 && dy == 0) {
                        continue;
                    }

                    int x = i;
                    int y = j;
                    string num = "";
                    while (x >= 0 && x < n && y >= 0 && y < m) {
                        num += arr[x][y];
                        if (check(stoi(num))) {
                            res = max(res, stoi(num));
                        }

                        x += dx;
                        y += dy;
                    }
                }
            }
        }
    }

    return res;
}

int main() {
    cin >> N >> M;

    char arr[10][10];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
        }
    }

    cout << solve(arr, N, M);

    return 0;
}