#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int input[101][101];
int arr[101][101];
bool visit[101][101];
int x_move[4] = { -1, 1, 0, 0 };
int y_move[4] = { 0, 0, -1, 1 };
vector<int> vc;
int cnt;

void dfs(int y, int x) {
    visit[y][x] = true;

    for (int d = 0; d < 4; d++) {
        int x_next = x + x_move[d];
        int y_next = y + y_move[d];

        if (x_next < 0 || x_next >= N || y_next < 0 || y_next >= N) {
            continue;
        }

        if (arr[y_next][x_next] && !visit[y_next][x_next]) {
            visit[y_next][x_next] = true;
            dfs(y_next, x_next);
        }
    }
}

void reset() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            arr[i][j] = 0;
            visit[i][j] = false;
        }
    }

    cnt = 0;
}

int main() {
    cin >> N;

    int maxHeight = -1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> input[i][j];

            if (input[i][j] > maxHeight) {
                maxHeight = input[i][j];
            }
        }
    }

    for (int h = 1; h <= maxHeight; h++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (input[i][j] < h) {
                    arr[i][j] = 0;
                }
                else {
                    arr[i][j] = 1;
                }
            }
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (arr[i][j] && !visit[i][j]) {
                    dfs(i, j);
                    cnt += 1;
                }
            }
        }

        vc.push_back(cnt);

        reset();
    }

    sort(vc.begin(), vc.end());

    cout << vc[vc.size() - 1];

    return 0;
}