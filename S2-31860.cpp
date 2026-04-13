#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M, K;
int today;
priority_queue<int, vector<int>> pq;
queue<int> qu;

int main() {
    qu.push(0);

    cin >> N >> M >> K;
    for (int i = 0; i < N; i++) {
        int D;
        cin >> D;

        pq.push(D);
    }

    while (!pq.empty()) {
        today = pq.top();
        pq.pop();

        qu.push(today + qu.back() / 2);

        today -= M;
        if (today > K) {
            pq.push(today);
        }
    }
    qu.pop();

    cout << qu.size() << "\n";
    while (!qu.empty()) {
        cout << qu.front() << "\n";
        qu.pop();
    }

    return 0;
}