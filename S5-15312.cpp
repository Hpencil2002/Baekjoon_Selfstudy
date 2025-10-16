#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int alp[26] = { 3, 2, 1, 2, 3, 3, 2, 3, 3, 2, 2, 1, 2, 2, 1, 2, 2, 2, 1, 2, 1, 1, 1, 2, 2, 1 };

int main() {
    string A, B;
    cin >> A >> B;

    queue<int> qu, nextQu;
    for (int i = 0; i < A.size(); i++) {
        qu.push(alp[A[i] - 'A']);
        qu.push(alp[B[i] - 'A']);
    }

    while (true) {
        int l = qu.front();
        qu.pop();

        while (!qu.empty()) {
            int r = qu.front();
            nextQu.push((l + r) % 10);
            l = r;
            qu.pop();
        }

        qu = nextQu;
        nextQu = queue<int>();

        if (qu.size() == 2) {
            break;
        }
    }

    while (!qu.empty()) {
        cout << qu.front();
        qu.pop();
    }

    return 0;
}