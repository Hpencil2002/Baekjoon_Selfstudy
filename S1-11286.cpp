#include <iostream>
#include <cmath>
#include <queue>
using namespace std;

int N;

struct cmp {
    bool operator() (int a, int b) {
        if (abs(a) == abs(b)) {
            return a > b;
        }
        else {
            return abs(a) > abs(b);
        }
    }
};

int main() {
    int N;
    priority_queue<int, vector<int>, cmp> pque;

    cin >> N;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;

        if (x == 0) {
            if (pque.empty()) {
                cout << 0 << "\n";
            }
            else {
                cout << pque.top() << "\n";
                pque.pop();
            }
        }
        else {
            pque.push(x);
        }
    }

    return 0;
}