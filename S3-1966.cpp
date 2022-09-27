#include <iostream>
#include <queue>
using namespace std;

int main() {
    int test, N, M, importance, count;
    cin >> test;

    for (int i = 0; i < test; i++) {
        count = 0;

        cin >> N >> M;
        queue<pair<int, int>> qu;
        priority_queue<int> pq;
        
        for (int j = 0; j < N; j++) {
            cin >> importance;
            qu.push({j, importance});
            pq.push(importance);
        }

        while (!qu.empty()) {
            int index = qu.front().first;
            int val = qu.front().second;
            qu.pop();

            if (pq.top() == val) {
                pq.pop();
                count += 1;
                if (index == M) {
                    cout << count << "\n";
                    break;
                }
            }
            else {
                qu.push({index, val});
            }
        }
    }

    return 0;
}