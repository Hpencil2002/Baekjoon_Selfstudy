#include <iostream>
#include <queue>
using namespace std;

int A, K;
int visit[1000001];

void bfs() {
    queue<int> qu;

    qu.push(A);
    visit[A] = 0;

    while (!qu.empty()) {
        int cur = qu.front();
        qu.pop();

        int num[2] = { cur + 1, cur * 2 };
        for (int i = 0; i < 2; i++) {
            if (num[i] <= K && visit[num[i]] > visit[cur] + 1) {
                visit[num[i]] = visit[cur] + 1;
                qu.push(num[i]);
            }
        }
    }
}

int main() {
    cin >> A >> K;
    fill(visit, visit + K + 1, 1e9);

    bfs();

    cout << visit[K];

    return 0;
}