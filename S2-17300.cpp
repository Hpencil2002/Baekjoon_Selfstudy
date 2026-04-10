#include <iostream>
using namespace std;

int L;
bool visit[10];

int main() {
    cin >> L;

    int prev = 0, cur = 0;
    for (int i = 0; i < L; i++) {
        prev = cur;
        cin >> cur;

        if (visit[cur]) {
            cout << "NO";
            return 0;
        }

        visit[cur] = true;
        if (prev == 0) {
            continue;
        }

        if (!visit[2]) {
            if (cur + prev == 4) {
                cout << "NO";
                return 0;
            }
        }
        if (!visit[4]) {
            if ((cur == 1 && prev == 7) || (cur == 7 && prev == 1)) {
                cout << "NO";
                return 0;
            }
        }
        if (!visit[5]) {
            if (cur + prev == 10) {
                cout << "NO";
                return 0;
            }
        }
        if (!visit[6]) {
            if ((cur == 3 && prev == 9) || (cur == 9 && prev == 3)) {
                cout << "NO";
                return 0;
            }
        }
        if (!visit[8]) {
            if (cur + prev == 16) {
                cout << "NO";
                return 0;
            }
        }
    }

    cout << "YES";

    return 0;
}