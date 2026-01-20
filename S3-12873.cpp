#include <iostream>
#include <queue>
using namespace std;

int N;
queue<int> qu;

int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        qu.push(i);
    }

    long long t = 1;
    while (qu.size() != 1) {
        long long cnt = t * t * t;
        cnt %= qu.size();

        if (!cnt) {
            cnt = qu.size();
        }

        while (--cnt) {
            qu.push(qu.front());
            qu.pop();
        }

        qu.pop();
        t += 1;
    }

    cout << qu.front();

    return 0;
}