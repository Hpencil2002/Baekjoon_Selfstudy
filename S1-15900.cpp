#include <iostream>
#include <vector>
using namespace std;

int N;
int a, b;
int cnt = 0;
int height = 0;
vector<int> vc[500001];
vector<int> visit;

void dfs(int x, int dep) {
    visit[x] = 1;

    if (x != 1 && vc[x].size() == 1) {
        cnt += 1;
        height += dep;

        return;
    }

    for (int i = 0; i < vc[x].size(); i++) {
        if (visit[vc[x][i]] != 0) {
            continue;
        }

        visit[vc[x][i]] = 1;
        dfs(vc[x][i], dep + 1);
    }
}

int main() {
    cin >> N;

    visit.resize(N + 1);
    for (int i = 0; i < N - 1; i++) {
        cin >> a >> b;

        vc[a].push_back(b);
        vc[b].push_back(a);
    }

    dfs(1, 0);

    if (height % 2 == 1) {
        cout << "Yes";
    }
    else {
        cout << "No";
    }

    return 0;
}