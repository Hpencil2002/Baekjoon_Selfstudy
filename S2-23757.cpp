#include <iostream>
#include <queue>
using namespace std;

int N, M;
int c, w;
priority_queue<int, vector<int>> pqu;

int main() {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> c;
        pqu.push(c);
    }

    for (int i = 0; i < M; i++) {
        cin >> w;
        if (w > pqu.top()) {
            cout << 0;

            return 0;
        }

        int tmp = pqu.top();
        tmp -= w;

        pqu.pop();
        pqu.push(tmp);
    }

    cout << 1;

    return 0;
}