#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int M, N;
int arr[2001][2001];
int output[2001][2001];
int save[2001][2001];
int ans;

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        string str;
        cin >> str;

        for (int j = 0; j < M; j++) {
            arr[i][j] = str[j] - '0';
        }
    }

    if (M == 1) {
        cout << 0;

        return 0;
    }

    for (int i = 0; i < N; i++) {
        output[i][0] = arr[i][0];
    }

    for (int j = 1; j < M; j++) {
        for (int i = 0; i < N; i++) {
            save[i][j] = output[i][j - 1];

            if (i - 1 >= 0) {
                save[i][j] = max(output[i - 1][j - 1], save[i][j]);
            }
            if (i + 1 < N) {
                save[i][j] = max(output[i + 1][j - 1], save[i][j]);
            }

            output[i][j] = save[i][j] + arr[i][j];
            ans = max(save[i][j], ans);
        }
    }

    cout << ans;

    return 0;
}