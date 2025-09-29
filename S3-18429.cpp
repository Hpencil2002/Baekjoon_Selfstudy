#include <iostream>
#include <vector>
using namespace std;

int N, K, ans;
vector<int> vc;

bool visited[9];

void dfs(int depth, int power) {
    if (depth == N - 1 && power >= 500) {
        ans += 1;
        return;
    }

    for (int i = 0; i < N; i++) {
        if (visited[i]) {
            continue;
        }

        visited[i] = true;
        if (power - K + vc[i] >= 500) {
            dfs(depth + 1, power - K + vc[i]);
        }
        visited[i] = false;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;

        vc.push_back(tmp);
    }

    dfs(0, 500);

    cout << ans;

    return 0;
}