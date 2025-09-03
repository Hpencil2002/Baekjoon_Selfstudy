#include <iostream>
#include <deque>
using namespace std;

bool visited[128];

int main() {
    int N, K;
    cin >> N >> K;

    deque<char> dq;
    for (int i = 0; i < N; i++) {
        dq.push_back('?');
    }

    while (K--) {
        int M;
        char c;
        cin >> M >> c;

        M--;
        while (M--) {
            dq.push_back(dq.front());
            dq.pop_front();
        }

        if (dq.front() == '?') {
            if (visited[c]) {
                cout << '!';
                return 0;
            }

            dq.push_back(c);
            dq.pop_front();
            visited[c] = true;
        }
        else if (dq.front() == c) {
            dq.push_back(c);
            dq.pop_front();
        }
        else {
            cout << '!';
            return 0;
        }
    }

    while (!dq.empty()) {
        cout << dq.back();
        dq.pop_back();
    }

    return 0;
}