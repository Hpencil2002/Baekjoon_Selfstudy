#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    int check_row = 0;
    int check_col = 0;

    char arr[50][50];
    bool row[50] = { false, };
    bool col[50] = { false, };

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];

            if (arr[i][j] == 'X') {
                row[i] = true;
                col[j] = true;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        if (!row[i]) {
            check_row += 1;
        }
    }
    for (int i =0 ; i < M; i++) {
        if (!col[i]) {
            check_col += 1;
        }
    }

    int ans = max(check_col, check_row);
    cout << ans;

    return 0;
}