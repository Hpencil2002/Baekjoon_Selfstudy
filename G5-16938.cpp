#include <iostream>
#include <vector>
using namespace std;

int N, L, R, X;
int problem[15];
bool visit[15];
vector<int> vc;
int ans;

void dfs(int index, int cnt, int levelSum) {
    if (cnt >= 2) {
        int Min = 987654321;
        int Max = -987654321;
        int sum = 0;

        for (int i = 0; i < vc.size(); i++) {
            sum += problem[vc[i]];

            if (problem[vc[i]] < Min) {
                Min = problem[vc[i]];
            }
            if (problem[vc[i]] > Max) {
                Max = problem[vc[i]];
            }
        }

        if (L <= sum && sum <= R && Max - Min >= X) {
            ans += 1;
        }
    }

    for (int i = index; i < N; i++) {
        if (visit[i]) {
            continue;
        }

        if (levelSum + problem[i] <= R) {
            visit[i] = true;
            vc.push_back(i);
            dfs(i, cnt + 1, levelSum + problem[i]);
            vc.pop_back();
            visit[i] = false;
        }
    }
}

int main() {
    cin >> N >> L >> R >> X;
    for (int i = 0; i < N; i++) {
        cin >> problem[i];
    }

    dfs(0, 0, 0);

    cout << ans;

    return 0;
}