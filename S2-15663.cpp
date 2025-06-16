#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int num[10];
int ans[10];
bool used[10];

void solve(int L) {
    if (L == M) {
        for (int i = 0; i < M; i++) {
            cout << ans[i] << ' ';
        }
        cout << "\n";
        return;
    }

    int tmp = 0;
    for (int i = 0; i < N; i++) {
        if (!used[i] && tmp != num[i]) {
            ans[L] = num[i];
            tmp = num[i];
            used[i] = true;
            solve(L + 1);
            used[i] = false;
        }
    }
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> num[i];
    }

    sort(num, num + N);

    solve(0);

    return 0;
}