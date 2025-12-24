#include <iostream>
using namespace std;

int N, M, K;
int ans = -987654321;
int arr[11][11];
int visit[11][11];

void solve(int r, int c, int num, int sum) {
    if (num == K) {
        if (sum > ans) {
            ans = sum;
        }

        return;
    }

    if (c > M) {
        r += 1;
        c = 1;
    }
    if (r > N) {
        return;
    }

    int i = r, j = c;
    while (i <= N) {
        if (!visit[i - 1][j]) {
            visit[i][j] = 1;
            solve(i, j + 2, num + 1, sum + arr[i][j]);
            visit[i][j] = 0;
        }

        j += 1;

        if (j > M) {
            i += 1;
            j = 1;
        }
    }
}

int main() {
    cin >> N >> M >> K;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> arr[i][j];
        }
    }

    solve(1, 1, 0, 0);

    cout << ans;

    return 0;
}