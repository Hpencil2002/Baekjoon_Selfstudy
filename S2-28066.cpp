#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int N, K;
queue<int> qu;

int main() {
    cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        qu.push(i);
    }

    while (qu.size() > 1) {
        int cur = qu.front();
        int cnt = min(K, (int)qu.size());

        for (int i = 0; i < cnt; i++) {
            qu.pop();
        }

        qu.push(cur);
    }

    cout << qu.front();

    return 0;
}