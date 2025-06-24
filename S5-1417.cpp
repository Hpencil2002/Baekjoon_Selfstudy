#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

priority_queue<int> pq;

int main() {
    int N;
    cin >> N;

    int ans = 0, dasom, in;
    cin >> dasom;
    N -= 1;
    while (N--) {
        cin >> in;
        if (in >= dasom) {
            pq.push(in);
        }
    }

    while (!pq.empty() && pq.top() >= dasom) {
        int tp = pq.top();
        pq.pop();

        tp -= 1;
        ans += 1;
        dasom += 1;

        pq.push(tp);
    }

    cout << ans;

    return 0;
}