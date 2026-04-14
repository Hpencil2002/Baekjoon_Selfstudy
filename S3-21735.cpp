#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int N, M;
int ans;
vector<int> vc = vector<int>(101, 0);

void solve(int index, int cnt, int size) {
    if (index >= N || cnt == M) {
        ans = max(ans, size);

        return;
    }

    solve(index + 1, cnt + 1, size + vc[index + 1]);
    solve(index + 2, cnt + 1, size / 2 + vc[index + 2]);
}

int main() {
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> vc[i];
    }

    solve(0, 0, 1);

    cout << ans;

    return 0;
}