#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int N, K;
int S, X, Y;
int arr[1001][1001];
int x_move[4] = { 1, 0, -1, 0 };
int y_move[4] = { 0, 1, 0, -1 };

struct cmp {
    bool operator() (pair<int, pair<int, int>> a, pair<int, pair<int, int>> b) {
        if (a.first != b.first) {
            return a.first > b.first;
        }
        else {
            return arr[a.second.first][a.second.second] > arr[b.second.first][b.second.second];
        }
    }
};
priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, cmp> pq;

void bfs() {
    while (!pq.empty()) {
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        int cur = pq.top().first;
        pq.pop();

        if (cur == S + 1) {
            break;
        }

        for (int d = 0; d < 4; d++) {
            int x_next = x + x_move[d];
            int y_next = y + y_move[d];

            if (x_next >= 1 && x_next <= N && y_next >= 1 && y_next <= N) {
                if (!arr[x_next][y_next]) {
                    arr[x_next][y_next] = arr[x][y];
                    pq.push({ cur + 1, { x_next, y_next } });
                }
            }
        }
    }
}

int main() {
    cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> arr[i][j];
            if (arr[i][j]) {
                pq.push({ 1, { i, j } });
            }
        }
    }
    cin >> S >> X >> Y;

    bfs();

    cout << arr[X][Y];

    return 0;
}