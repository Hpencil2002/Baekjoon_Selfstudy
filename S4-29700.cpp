#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, K;
vector<vector<int>> vc;
vector<vector<int>> sums;
int ans;

int main() {
    cin >> N >> M >> K;

    vc = vector<vector<int>>(N, vector<int>(M, 0));
    sums = vector<vector<int>>(N, vector<int>(M, 0));
    for (int i = 0; i < N; i++) {
        string str;
        cin >> str;

        for (int j = 0; j < M; j++) {
            vc[i][j] = (str[j] - '0');
        }
    }

    for (int i = 0; i < N; i++) {
        sums[i][0] = vc[i][0] == 0 ? 1 : 0;

        for (int j = 1; j < M; j++) {
            if (vc[i][j] == 0) {
                sums[i][j] = sums[i][j - 1] + 1;
            }
            else {
                sums[i][j] = 0;
            }
        }

        int maxSum = 0;
        for (int j = 0; j < M; j++) {
            maxSum = sums[i][j];

            if (maxSum >= K) {
                ans += 1;
            }
        }
    }

    cout << ans;

    return 0;
}