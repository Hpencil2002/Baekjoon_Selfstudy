#include <iostream>
#include <queue>
using namespace std;

int main() {
    int N;
    cin >> N;

    queue<int> qu;
    int num;
    while (true) {
        cin >> num;
        if (num == -1) {
            break;
        }

        if (num > 0) {
            if (qu.size() < N) {
                qu.push(num);
            }
        }
        if (num == 0) {
            qu.pop();
        }
    }

    if (qu.empty()) {
        cout << "empty";
    }
    else {
        while (!qu.empty()) {
            cout << qu.front() << ' ';
            qu.pop();
        }
    }

    return 0;
}