#include <iostream>
#include <string>
#include <vector>
using namespace std;

int N, M;
vector<vector<bool>> vc;
int ans;

void solve(int x, int y) {
    for (int i = 0; i <= x; i++) {
        for (int j = 0; j <= y; j++) {
            vc[i][j] = !vc[i][j];
        }
    }

    ans += 1;
}

int main() {
    cin >> N >> M;
    vc.resize(N, vector<bool>());

    string tmp;
    for (int i = 0; i < N; i++) {
        cin >> tmp;

        for (int j = 0; j < M; j++) {
            if (tmp[j] == '0') {
                vc[i].push_back(false);
            }
            else {
                vc[i].push_back(true);
            }
        }
    }

    for (int i = N - 1; i >= 0; i--) {
        for (int j = M - 1; j >= 0; j--) {
            if (vc[i][j]) {
                solve(i, j);
            }
        }
    }

    cout << ans;

    return 0;
}