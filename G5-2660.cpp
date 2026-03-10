#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

int N;
vector<int> vc[51];
vector<pair<int, int>> score;
bool visit[51];

bool comp(const pair<int, int>& a, const pair<int, int>& b) {
    if (a.second == b.second) {
        return a.first < b.first;
    }

    return a.second < b.second;
}

void bfs(int i) {
    queue<pair<int, int>> qu;
    int total = 0;

    visit[i] = true;
    qu.push({ i, 0 });

    while (!qu.empty()) {
        int cur = qu.front().first;
        int level = qu.front().second;
        total = max(total, level);
        qu.pop();

        for (int d = 0; d < vc[cur].size(); d++) {
            int next = vc[cur][d];

            if (!visit[next]) {
                visit[next] = true;
                qu.push({ next, level + 1 });
            }
        }
    }

    score.push_back({ i, total });
}

int getCandidate() {
    int minScore = score[0].second;
    int res = 0;

    for (auto i : score) {
        int val = i.second;
        if (val > minScore) {
            break;
        }

        res += 1;
    }

    return res;
}

void printCandidate(int minScore) {
    for (auto i : score) {
        int person = i.first;
        int val = i.second;

        if (val > minScore) {
            return;
        }

        cout << person << ' ';
    }
}

int main() {
    cin >> N;
    while (true) {
        int u, v;
        cin >> u >> v;
        if (u == -1 && v == -1) {
            break;
        }

        vc[u].push_back(v);
        vc[v].push_back(u);
    }

    for (int i = 1; i <= N; i++) {
        memset(visit, false, sizeof(visit));
        bfs(i);
    }

    sort(score.begin(), score.end(), comp);

    int num = getCandidate();
    int minScore = score[0].second;

    cout << minScore << ' ' << num << "\n";
    printCandidate(minScore);

    return 0;
}