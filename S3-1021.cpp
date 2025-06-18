#include <iostream>
#include <deque>
using namespace std;

int main() {
    deque<int> dq;
    int index;
    int ans = 0;

    int N, M, x;
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        dq.push_back(i);
    }

    while (M--) {
        cin >> x;

        for (int i = 0; i < dq.size(); i++) {
            if (dq[i] == x) {
                index = i;
                break;
            }
        }

        if (index <= dq.size() / 2) {
            while (1) {
                if (dq.front() == x) {
                    dq.pop_front();
                    break;
                }
                ans += 1;
                dq.push_back(dq.front());
                dq.pop_front();
            }
        }
        else {
            while (1) {
                if (dq.front() == x) {
                    dq.pop_front();
                    break;
                }
                ans += 1;
                dq.push_front(dq.back());
                dq.pop_back();
            }
        }
    }

    cout << ans;

    return 0;
}