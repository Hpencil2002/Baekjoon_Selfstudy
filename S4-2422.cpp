#include <iostream>
using namespace std;

int N, M;
int cnt;
bool x[201][201];
int ans[3];

void recur(int index, int cur) {
    if (cur == 3) {
        cnt += 1;
        return;
    }

    for (int i = index + 1; i < N + 1; i++) {
        if (cur == 2 && x[ans[0]][i]) {
            continue;
        }
        if (x[index][i]) {
            continue;
        }

        ans[cur] = i;
        recur(i, cur + 1);
    }
}

int main() {
    cin >> N >> M;

    int a, b;
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        x[a][b] = 1;
        x[b][a] = 1;
    }

    recur(0, 0);

    cout << cnt;

    return 0;
}