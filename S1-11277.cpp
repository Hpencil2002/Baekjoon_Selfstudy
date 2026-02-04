#include <iostream>
#include <vector>
using namespace std;

int N, M;
int ans;
vector<pair<int, int>> vc;
vector<bool> state;

void dfs(int dep) {
    if (dep == N + 1) {
        bool check = true;

        for (int i = 1; i < vc.size(); i++) {
            bool left, right;

            if (vc[i].first < 0) {
                left = !state[-vc[i].first];
            }
            else {
                left = state[vc[i].first];
            }

            if (vc[i].second < 0) {
                right = !state[-vc[i].second];
            }
            else {
                right = state[vc[i].second];
            }

            if (!left && !right) {
                check = false;
            }
        }

        if (check) {
            ans = 1;
        }

        return;
    }

    for (int i = 0; i < 2; i++) {
        if (i == 0) {
            state[dep] = true;
        }
        else {
            state[dep] = false;
        }

        dfs(dep + 1);
    }
}

int main() {
    cin >> N >> M;

    vc.resize(M + 1);
    state.resize(N + 1, true);

    for (int i = 1; i <= M; i++) {
        cin >> vc[i].first >> vc[i].second;
    }

    dfs(1);

    cout << ans;

    return 0;
}