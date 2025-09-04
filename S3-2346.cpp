#include <iostream>
#include <deque>
using namespace std;

int main() {
    int N;
    cin >> N;

    deque<pair<int, int>> dq;
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        dq.push_back({num, i + 1});
    }

    while (!dq.empty()) {
        int index = dq.front().first;
        cout << dq.front().second << ' ';
        dq.pop_front();

        if (dq.empty()) {
            break;
        }

        if (index > 0) {
            for (int i = 0; i < index - 1; i++) {
                dq.push_back(dq.front());
                dq.pop_front();
            }
        }
        else {
            for (int i = 0; i < (-1) * index; i++) {
                dq.push_front(dq.back());
                dq.pop_back();
            }
        }
    }

    return 0;
}