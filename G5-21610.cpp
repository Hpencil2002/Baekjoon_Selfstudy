#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int N, M;
int arr[55][55];
bool cloudArr[55][55];
vector<pair<int, int>> cloud;
vector<pair<int, int>> cmd;
int x_move[9] = { 0, 0, -1, -1, -1, 0, 1, 1, 1 };
int y_move[9] = { 0, -1, -1, 0, 1, 1, 1, 0, -1 };

int makeRange(int x) {
    if (x < 0) {
        return N - 1;
    }

    if (x >= N) {
        return 0;
    }

    return x;
}

void moveCloud(int index) {
    int dir = cmd[index].first;
    int cnt = cmd[index].second;
    memset(cloudArr, false, sizeof(cloudArr));

    for (int i = 0; i < cloud.size(); i++) {
        int x = cloud[i].first;
        int y = cloud[i].second;

        int x_next = x;
        int y_next = y;
        for (int d = 0; d < cnt; d++) {
            x_next += x_move[dir];
            y_next += y_move[dir];
            x_next = makeRange(x_next);
            y_next = makeRange(y_next);
        }

        cloud[i].first = x_next;
        cloud[i].second = y_next;
    }

    for (int i = 0; i < cloud.size(); i++) {
        int x = cloud[i].first;
        int y = cloud[i].second;
        cloudArr[x][y] = true;
    }
}

void makeRain() {
    for (int i = 0; i < cloud.size(); i++) {
        int x = cloud[i].first;
        int y = cloud[i].second;
        arr[x][y] += 1;
    }
}

void waterBug() {
    for (int i = 0; i < cloud.size(); i++) {
        int x = cloud[i].first;
        int y = cloud[i].second;
        int cnt = 0;

        for (int d = 2; d <= 8; d += 2) {
            int x_next = x + x_move[d];
            int y_next = y + y_move[d];

            if (x_next < 0 || x_next >= N || y_next < 0 || y_next >= N) {
                continue;
            }

            if (arr[x_next][y_next] >= 1) {
                cnt += 1;
            }
        }

        arr[x][y] += cnt;
    }
}

void deleteCloud() {
    cloud.clear();
}

void makeCloud() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (cloudArr[i][j]) {
                continue;
            }
            if (arr[i][j] < 2) {
                continue;
            }

            arr[i][j] -= 2;
            cloud.push_back({ i, j });
        }
    }

    memset(cloudArr, false, sizeof(cloudArr));

    for (int i = 0; i < cloud.size(); i++) {
        int x = cloud[i].first;
        int y = cloud[i].second;
        cloudArr[x][y] = true;
    }
}

int findAnswer() {
    int ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            ans += arr[i][j];
        }
    }

    return ans;
}

int main() {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < M; i++) {
        int d, s;
        cin >> d >> s;

        cmd.push_back({ d, s });
    }

    cloud.push_back({ N - 2, 0 });
    cloud.push_back({ N - 2, 1 });
    cloud.push_back({ N - 1, 0 });
    cloud.push_back({ N - 1, 1 });
    cloudArr[N - 2][0] = true;
    cloudArr[N - 2][1] = true;
    cloudArr[N - 1][0] = true;
    cloudArr[N - 1][1] = true;

    for (int i = 0; i < M; i++) {
        moveCloud(i);
        makeRain();
        waterBug();
        deleteCloud();
        makeCloud();
    }

    cout << findAnswer();

    return 0;
}