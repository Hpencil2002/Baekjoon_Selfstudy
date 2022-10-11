#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    queue<int> qu;

    cin >> N >> K;
    for (int i = 1; i < N + 1; i++) {
        qu.push(i);
    }

    cout << "<";
    int count = 1;

    while(!qu.empty()) {
        if (count % K == 0) {
            int ans = qu.front();
            qu.pop();
            if (qu.empty()) {
                cout << ans << ">";
            }
            else {
                cout << ans << ", ";
            }
        }
        else {
            int tmp = qu.front();
            qu.pop();
            qu.push(tmp);
        }

        count++;
    }

    return 0;
}