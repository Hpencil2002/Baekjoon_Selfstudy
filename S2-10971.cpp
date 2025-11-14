#include <iostream>
using namespace std;

int N;
int ans = 1e9;
int arr[10][10];
bool check[11] = { false, };

void solve(int start, int index, int cnt, int sum) {
    if (cnt == N) {
        if (arr[index][start] == 0) {
            return;
        }

        if (ans > sum + arr[index][start]) {
            ans = sum + arr[index][start];
        }
        return;
    }

    for (int i = 0; i < N; i++) {
        if (check[i] || arr[index][i] == 0) {
            continue;
        }

        check[i] = true;
        solve(start, i, cnt + 1, sum + arr[index][i]);
        check[i] = false;
    }
}

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        check[i] = true;
        solve(i, i, 1, 0);
        check[i] = false;
    }

    cout << ans;

    return 0;
}