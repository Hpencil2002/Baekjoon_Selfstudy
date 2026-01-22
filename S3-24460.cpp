#include <iostream>
#include <algorithm>
using namespace std;

int N;
int arr[1100][1100];

int solve(int x, int y, int n) {
    int ans[4] = { 0, };

    if (n >= 2) {
        ans[0] = solve(x, y, n / 2);
        ans[1] = solve(x, y + n / 2, n / 2);
        ans[2] = solve(x + n / 2, y, n / 2);
        ans[3] = solve(x + n / 2, y + n / 2, n / 2);

        sort(ans, ans + 4);

        return ans[1];
    }
    else {
        return arr[x][y];
    }
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }

    cout << solve(0, 0, N);

    return 0;
}