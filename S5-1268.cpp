#include <iostream>
using namespace std;

int N;
int student[1001][5];
bool check[1001][1001] = {false, };

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> student[i][j];
        }
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < N - 1; j++) {
            for (int k = j + 1; k < N; k++) {
                if (student[j][i] == student[k][i]) {
                    check[j][k] = check[k][j] = true;
                }
            }
        }
    }

    int ans = -1;
    int prev_cnt = -1;
    for (int i = 0; i < N; i++) {
        int cnt = 0;

        for (int j = 0; j < N; j++) {
            if (check[i][j]) {
                cnt += 1;
            }
        }

        if (cnt > prev_cnt) {
            ans = i + 1;
            prev_cnt = cnt;
        }
    }

    cout << ans;

    return 0;
}