#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

#define MAX 101

int N, M;
int maze[MAX][MAX];
int visited[MAX][MAX];
int dist[MAX][MAX];

int x_dir[4] = {-1, 1, 0, 0};
int y_dir[4] = {0, 0, -1, 1};

queue<pair<int, int>> qu;

void bfs(int start_x, int start_y);

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        string row;
        cin >> row;

        for (int j = 0; j < M; j++) {
            maze[i][j] = row[j] - '0';
        }
    }

    bfs(0, 0);

    cout << dist[N - 1][M - 1];

    return 0;
}

void bfs(int start_x, int start_y) {
    visited[start_x][start_y] = 1;
    qu.push(make_pair(start_x, start_y));
    dist[start_x][start_y] += 1;

    while(!qu.empty()) {
        int x = qu.front().first;
        int y = qu.front().second;
        qu.pop();

        for (int i = 0; i < 4; i++) {
            int x_new = x + x_dir[i];
            int y_new = y + y_dir[i];

            if ((x_new >= 0 && x_new < N) && (y_new >= 0 && y_new < M) && !visited[x_new][y_new] && maze[x_new][y_new] == 1) {
                visited[x_new][y_new] = 1;
                qu.push(make_pair(x_new, y_new));
                dist[x_new][y_new] = dist[x][y] + 1;
            }
        }
    }
}