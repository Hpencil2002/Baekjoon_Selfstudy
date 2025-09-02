#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        string current, goal;
        cin >> current >> goal;

        int w = 0;
        int b = 0;
        for (int i = 0; i < N; i++) {
            if (current[i] == goal[i]) {
                continue;
            }
            else {
                if (current[i] == 'B') {
                    b += 1;
                }
                else {
                    w += 1;
                }
            }
        }

        if (w > b) {
            cout << w << "\n";
        }
        else {
            cout << b << "\n";
        }
    }

    return 0;
}