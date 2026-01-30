#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
char arr[101][101];
vector<pair<pair<int, int>, int>> ans;
int visit[101][101];
int x_move[4] = { -1, 0, 1, 0 };
int y_move[4] = { 0, -1, 0, 1 };

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
        }
    }

    int tmp = min(N, M);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (arr[i][j] == '*') {
                int num = 0;
                vector<pair<int, int>> vc;
                vc.push_back({ i, j });

                for (int k = 1; k <= (tmp / 2); k++) {
                    bool check = true;

                    for (int d = 0; d < 4; d++) {
                        int x_next = i + (x_move[d] * k);
                        int y_next = j + (y_move[d] * k);

                        if (x_next >= 0 && x_next < N && y_next >= 0 && y_next < M && arr[x_next][y_next] == '*') {
                            vc.push_back({ x_next, y_next });
                        }
                        else {
                            check = false;

                            break;
                        }
                    }

                    if (!check) {
                        break;
                    }

                    num += 1;
                }

                if (num > 0) {
                    ans.push_back({ { i, j }, num });
                    for (int d = 0; d < vc.size(); d++) {
                        visit[vc[d].first][vc[d].second] = 1;
                    }
                }
            }
        }
    }

    bool check = true;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (arr[i][j] == '*' && !visit[i][j]) {
                check = false;
            }
        }
    }

    if (!check) {
        cout << -1;
    }
    else {
        if (ans.size() == 0) {
            cout << -1;
        }
        else {
            cout << ans.size() << "\n";

            for (int i = 0; i < ans.size(); i++) {
                cout << ans[i].first.first + 1 << ' ' << ans[i].first.second + 1 << ' ' << ans[i].second << "\n";
            }
        }
    }

    return 0;
}