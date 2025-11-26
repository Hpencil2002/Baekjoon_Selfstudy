#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Team
{
    vector<int> scores;
    int id = 0;
    int cnt = 0;
    int time = 0;
    int sum = 0;
};

bool comp(const Team& a, const Team& b) {
    if (a.sum == b.sum) {
        if (a.cnt == b.cnt) {
            return a.time < b.time;
        }

        return a.cnt < b.cnt;
    }

    return a.sum > b.sum;
}

int main() {
    int T;
    cin >> T;

    vector<int> ans = vector<int>(T);
    for (int d = 0; d < T; d++) {
        int n, k, t, m;
        cin >> n >> k >> t >> m;

        vector<Team> vc = vector<Team>(n);
        for (int i = 0; i < n; i++) {
            vc[i].scores.resize(k);
            vc[i].id = i + 1;
        }

        for (int i = 0; i < m; i++) {
            int curID = 0;
            int curProb = 0;
            int curScore = 0;

            cin >> curID >> curProb >> curScore;

            vc[curID - 1].cnt += 1;
            vc[curID - 1].time = i;

            if (curScore > vc[curID - 1].scores[curProb - 1]) {
                vc[curID - 1].sum -= vc[curID - 1].scores[curProb - 1];
                vc[curID - 1].sum += curScore;

                vc[curID - 1].scores[curProb - 1] = curScore;
            }
        }

        sort(vc.begin(), vc.end(), comp);

        for (int i = 0; i < n; i++) {
            if (vc[i].id == t) {
                ans[d] = i + 1;
                break;
            }
        }
    }

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << "\n";
    }

    return 0;
}