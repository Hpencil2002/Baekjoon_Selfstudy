#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int arr[30][30];
int pick[3];
int ans;

void solve(int index, int cnt) {
    if (cnt != -1) {
        pick[cnt] = index;
    }
    if (cnt == 2) {
        int sum = 0;
        for (int i = 0; i < N; i++) {
            int score = 0;
            for (int j = 0; j < 3; j++) {
                score = max(arr[i][pick[j]], score);
            }

            sum += score;
        }

        ans = max(sum, ans);

        return;
    }

    for (int i = index; i < M; i++) {
        solve(i + 1, cnt + 1);
    }
}

int main() {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
        }
    }

    solve(-1, -1);

    cout << ans;

    return 0;
}