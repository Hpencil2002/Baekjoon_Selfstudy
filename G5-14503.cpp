#include <iostream>
using namespace std;

int N, M;
int r, c, d;
int ans;
int arr[50][50];
bool visit[50][50];
int r_move[4] = { -1, 0, 1, 0 };
int c_move[4] = { 0, 1, 0, -1 };

void dfs() {
    for (int i = 0; i < 4; i++) {
        int next = (d + 3 - i) % 4;
        int r_next = r + r_move[next];
        int c_next = c + c_move[next];

        if (r_next < 0 || r_next >= N || c_next < 0 || c_next >= M || arr[r_next][c_next] == 1) {
            continue;
        }

        if (arr[r_next][c_next] == 0 && !visit[r_next][c_next]) {
            visit[r_next][c_next] = true;
            r = r_next;
            c = c_next;
            d = next;
            ans += 1;

            dfs();
        }
    }

    int back_index = d > 1 ? d - 2: d + 2;
    int r_back = r + r_move[back_index];
    int c_back = c + c_move[back_index];

    if (r_back >= 0 && r_back <= N || c_back >= 0 || c_back <= M) {
        if (arr[r_back][c_back] == 0) {
            r = r_back;
            c = c_back;

            dfs();
        }
        else {
            cout << ans;
            exit(0);
        }
    }
}

int main() {
    cin >> N >> M;
    cin >> r >> c >> d;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
        }
    }

    visit[r][c] = true;
    ans += 1;

    dfs();

    return 0;
}