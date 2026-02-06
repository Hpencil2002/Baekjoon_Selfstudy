#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int N, M;

void dfs(int cnt, vector<bool>& sel, bool& pass, const int n, const vector<pair<int, int>>& clauses) {
    if (pass) {
        return;
    }

    if (cnt == N + 1) {
        pass = true;
        cout << "1\n";

        for (int i = 0; i < cnt - 1; i++) {
            cout << (sel[i] ? 1 : 0) << ' ';
        }

        return;
    }

    for (auto& clause : clauses) {
        int a = clause.first;
        int b = clause.second;

        if (abs(a) <= cnt && abs(b) <= cnt) {
            bool res = false;

            res |= (a > 0 ? sel[abs(a) - 1] : !sel[abs(a) - 1]);
            res |= (b > 0 ? sel[abs(b) - 1] : !sel[abs(b) - 1]);

            if (!res) {
                return;
            }
        }
    }

    sel.push_back(true);
    dfs(cnt + 1, sel, pass, n, clauses);
    sel.pop_back();

    sel.push_back(false);
    dfs(cnt + 1, sel, pass, n, clauses);
    sel.pop_back();
}

int main() {
    cin >> N >> M;

    vector<pair<int, int>> clauses = vector<pair<int, int>>(M);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;

        clauses[i].first = a;
        clauses[i].second = b;
    }

    vector<bool> sel;
    bool pass = false;

    dfs(0, sel, pass, N, clauses);

    if (!pass) {
        cout << "0\n";
    }

    return 0;
}