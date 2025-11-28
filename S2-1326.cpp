#include <iostream>
#include <queue>
using namespace std;

int N, a, b;
int arr[10001];
int record[10001];
bool visit[10001] = { false, };

void bfs(int start, int end) {
    queue<int> qu;

    qu.push(start);
    visit[start] = true;

    while (!qu.empty()) {
        int cur = qu.front();
        qu.pop();

        if (cur == end) {
            return;
        }

        for (int i = cur + arr[cur]; i <= N; i += arr[cur]) {
            if (!visit[i]) {
                record[i] = record[cur] + 1;
                qu.push(i);
                visit[i] = true;
            }
        }

        for (int i = cur - arr[cur]; i >= 1; i -= arr[cur]) {
            if (!visit[i]) {
                record[i] = record[cur] + 1;
                qu.push(i);
                visit[i] = true;
            }
        }
    }
}

int main() {
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    cin >> a >> b;
    if (a == b) {
        cout << 0;

        return 0;
    }

    bfs(a, b);

    if (record[b] == 0) {
        cout << -1;
    }
    else {
        cout << record[b];
    }

    return 0;
}