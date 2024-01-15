#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n, k;
    queue<pair<int, int>> qu;
    int spot[100001] = {0};
    bool visited[100001] = {false};
    int result[100001] = {0};

    cin >> n >> k;
    qu.push(pair<int, int>(n, 0));
    while (!qu.empty()) {
        int now = qu.front().first, cnt = qu.front().second;
        qu.pop();

        if (!visited[now] && (now >= 0 && now < 100001)) {
            visited[now] = true;
            if (result[now] == 0) {
                result[now] = cnt;
            }
            cnt += 1;
            qu.push(pair<int, int>(now - 1, cnt));
            qu.push(pair<int, int>(now + 1, cnt));
            qu.push(pair<int, int>(now * 2, cnt));
        }
    }

    cout << result[k];

    return 0;
}