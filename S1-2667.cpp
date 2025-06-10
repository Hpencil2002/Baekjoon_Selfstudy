#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int N;
int ans = 0;
int cnt = 0;
vector<int> sizeVec;

int map[25][25];
int visited[25][25];
int x_move[4] = {-1, 0, 1, 0};
int y_move[4] = {0, 1, 0, -1};

void dfs(int x, int y) {
    for (int i = 0; i < 4; i++) {
        int nx = x + x_move[i];
        int ny = y + y_move[i];

        if (nx >= N || nx < 0 || ny >= N || ny < 0) {
            continue;
        }

        if (visited[nx][ny] == 0 && map[nx][ny] == 1) {
            visited[nx][ny] = 1;
            cnt += 1;
            dfs(nx, ny);
        }
    }
}

int main() {
    cin >> N;
    string str;

    for (int i = 0; i < N; i++) {
        cin >> str;
        for (int j = 0; j < str.length(); j++) {
            visited[i][j] = 0;

            if (str[j] == '1') {
                map[i][j] = 1;
            }
            else {
                map[i][j] = 0;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (map[i][j] == 1 && visited[i][j] == 0) {
                visited[i][j] = 1;
                cnt = 1;
                dfs(i, j);
                sizeVec.push_back(cnt);
                ans += 1;
            }
        }
    }

    sort(sizeVec.begin(), sizeVec.end());

    cout << ans << "\n";
    for (int i = 0; i < sizeVec.size(); i++) {
        cout << sizeVec[i] << "\n";
    }

    return 0;
}