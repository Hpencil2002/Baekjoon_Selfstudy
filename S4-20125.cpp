#include <iostream>
#include <string>
using namespace std;

int ans[5];
int x_move[4] = { -1, 1, 0, 0 };
int y_move[4] = { 0, 0, -1, 1 };

int main() {
    int N;
    cin >> N;

    string cookie[1000];
    for (int i = 0; i < N; i++) {
        cin >> cookie[i];
    }

    pair<int, int> heart;
    for (int i = 1; i < N - 1; i++) {
        for (int j = 1; j < N - 1; j++) {
            bool flag = true;
            for (int k = 0; k < 4; k++) {
                if (cookie[i + x_move[k]][j + y_move[k]] != '*') {
                    flag = false;
                }
            }

            if (flag) {
                heart = {i, j};
                cout << i + 1 << ' ' << j + 1 << "\n";
                break;
            }
        }
    }

    pair<int, int> tmp = heart;

    while (tmp.second != 0 && cookie[tmp.first][--tmp.second] == '*') {
        ans[0] += 1;
    }
    tmp = heart;
    while (tmp.second != N - 1 && cookie[tmp.first][++tmp.second] == '*') {
        ans[1] += 1;
    }
    tmp = heart;
    while (tmp.first != N - 1 && cookie[++tmp.first][tmp.second] == '*') {
        ans[2] += 1;
    }

    tmp.first -= 1;
    pair<int, int> wrist = tmp;

    tmp.second -= 1;
    while (tmp.first != N - 1 && cookie[++tmp.first][tmp.second] == '*') {
        ans[3] += 1;
    }
    tmp = wrist;

    tmp.second += 1;
    while (tmp.first != N - 1 && cookie[++tmp.first][tmp.second] == '*') {
        ans[4] += 1;
    }

    for (int i = 0; i < 5; i++) {
        cout << ans[i] << ' ';
    }

    return 0;
}