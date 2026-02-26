#include <iostream>
#include <queue>
using namespace std;

int N, K;
int Start, End, cnt, ans;
int arr[220];
bool visit[220];
queue<int> qu;

void moveBelt() {
    Start -= 1;
    End -= 1;

    if (Start < 1) {
        Start = 2 * N;
    }
    if (End < 1) {
        End = 2 * N;
    }
}

void moveRobot() {
    int size = qu.size();

    for (int i = 0; i < size; i++) {
        int cur = qu.front();
        visit[cur] = false;
        qu.pop();

        if (cur == End) {
            continue;
        }

        int next = cur + 1;
        if (next > 2 * N) {
            next = 1;
        }

        if (arr[next] >= 1 && !visit[next]) {
            arr[next] -= 1;
            if (arr[next] == 0) {
                cnt += 1;
            }
            if (next == End) {
                continue;
            }

            visit[next] = true;
            qu.push(next);
        }
        else {
            visit[cur] = true;
            qu.push(cur);
        }
    }
}

void makeRobot() {
    if (!visit[Start] && arr[Start] >= 1) {
        visit[Start] = true;
        arr[Start] -= 1;
        qu.push(Start);

        if (arr[Start] == 0) {
            cnt += 1;
        }
    }
}

int main() {
    cin >> N >> K;
    for (int i = 1; i <= 2 * N; i++) {
        cin >> arr[i];
    }

    Start = 1;
    End = N;
    while (cnt < K) {
        ans += 1;

        moveBelt();
        moveRobot();
        makeRobot();
    }

    cout << ans;

    return 0;
}