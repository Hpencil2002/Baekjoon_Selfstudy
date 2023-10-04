#include <iostream>
#include <queue>
using namespace std;

int main() {
    int N, tmp;
    queue<int> qu1, qu2;

    cin >> N;
    for (int i = 1; i <= N; i++) {
        qu1.push(i);
    }

    while (qu1.size() != 1) {
        qu2.push(qu1.front());
        qu1.pop();

        tmp = qu1.front();
        qu1.pop();
        qu1.push(tmp);
    }

    while (!qu2.empty()) {
        cout << qu2.front() << " ";
        qu2.pop();
    }
    cout << qu1.front();

    return 0;
}