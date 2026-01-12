#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int N, K;
int cnt;
int ans = -1;
queue<int> qu_eat, qu_not;

int main() {
    cin >> N >> K;
    int M = N - K;

    while (K--) {
        int x;
        cin >> x;

        cnt += x;
        qu_eat.push(x);
    }
    while (M--) {
        int x;
        cin >> x;

        qu_not.push(x);
    }

    while (N--) {
        ans = max(ans, cnt);

        cnt -= qu_eat.front();
        qu_not.push(qu_eat.front());
        qu_eat.pop();

        cnt += qu_not.front();
        qu_eat.push(qu_not.front());
        qu_not.pop();
    }

    cout << ans;

    return 0;
}