#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, H, T;
priority_queue<int, vector<int>, less<int>> pqu;

int main() {
    cin >> N >> H >> T;
    for (int i = 0; i < N; i++) {
        int h;
        cin >> h;

        pqu.push(h);
    }

    for (int i = 0; i < T; i++) {
        int h = pqu.top();

        if (h < H) {
            cout << "YES\n" << i;

            return 0;
        }
        else if (h > 1) {
            pqu.pop();
            pqu.push(h / 2);
        }
    }

    if (pqu.top() >= H) {
        cout << "NO\n" << pqu.top();
    }
    else {
        cout << "YES\n" << T;
    }

    return 0;
}