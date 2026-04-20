#include <iostream>
#include <vector>
using namespace std;

bool check(vector<vector<int>>& vc) {
    int visit[10] = { 0, };
    int cnt = 0;

    for (int i = 0; i < 9; i++) {
        if (!visit[vc[0][i]]) {
            visit[vc[0][i]] = 1;
            cnt += 1;
        }
    }
    if (cnt != 9) {
        return false;
    }

    for (int i = 0; i < 9; i++) {
        fill(&visit[0], &visit[10], 0);
        cnt = 0;

        for (int j = 0; j < 9; j++) {
            if (!visit[vc[j][i]]) {
                visit[vc[j][i]] = 1;
                cnt += 1;
            }
        }
        if (cnt != 9) {
            return false;
        }
    }

    for (int i = 0; i < 9; i += 3) {
        for (int j = 0; j < 9; j += 3) {
            int x = i;
            int y = j;

            fill(&visit[0], &visit[10], 0);
            cnt = 0;

            for (int k = x; k < x + 3; k++) {
                for (int l = y; l < y + 3; l++) {
                    if (!visit[vc[k][l]]) {
                        visit[vc[k][l]] = 1;
                        cnt += 1;
                    }
                }
            }
            if (cnt != 9) {
                return false;
            }
        }
    }

    return true;
}

int main() {
    int T;
    cin >> T;

    for (int i = 1; i < T + 1; i++) {
        vector<vector<int>> vc;
        vc.resize(9, vector<int>(9, 0));
        for (auto& ele : vc) {
            for (auto& e : ele) {
                cin >> e;
            }
        }

        cout << "Case " << i << ": ";
        if (check(vc)) {
            cout << "CORRECT\n";
        }
        else {
            cout << "INCORRECT\n";
        }
    }

    return 0;
}