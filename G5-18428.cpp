#include <iostream>
#include <vector>
using namespace std;

int N;
char arr[7][7];
vector<pair<int, int>> teacher;
vector<pair<int, int>> none;
int x_move[4] = { -1, 1, 0, 0 };
int y_move[4] = { 0, 0, -1, 1 };

bool check(int row, int col) {
    for (int d = 0; d < 4; d++) {
        int row_next = row;
        int col_next = col;

        while (row_next >= 0 && row_next < N && col_next >= 0 && col_next < N) {
            row_next += x_move[d];
            col_next += y_move[d];

            if (arr[row_next][col_next] == 'O') {
                break;
            }

            if (arr[row_next][col_next] == 'S') {
                return false;
            }
        }
    }

    return true;
}

void dfs(int index, int count) {
    if (count == 3) {
        for (auto e : teacher) {
            if (!check(e.first, e.second)) {
                return;
            }
        }

        cout << "YES\n";

        exit(0);
    }

    for (int i = index; i < none.size(); i++) {
        arr[none[i].first][none[i].second] = 'O';
        dfs(i + 1, count + 1);
        arr[none[i].first][none[i].second] = 'X';
    }
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];

            if (arr[i][j] == 'T') {
                teacher.push_back({ i, j });
            }
            else if (arr[i][j] == 'X') {
                none.push_back({ i, j });
            }
        }
    }

    dfs(0, 0);

    cout << "NO\n";

    return 0;
}