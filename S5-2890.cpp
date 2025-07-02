#include <iostream>
#include <string>
#include <set>
using namespace std;

int main() {
    int R, C;
    cin >> R >> C;

    int poses[9];
    for (int i = 0; i < R; i++) {
        int pos = -1;
        int team = -1;
        string row;

        cin >> row;
        for (int j = 0; j < C; j++) {
            if (row[j] != 'S' && row[j] != '.' && row[j] != 'F') {
                team = row[j] - '1';
                pos = j;
                break;
            }
        }

        if (pos != -1 && team != -1) {
            poses[team] = pos;
        }
    }

    for (int i = 0; i < 9; i++) {
        int rank = 1;
        set<int> uniquePos;

        for (int j = 0; j < 9; j++) {
            if (poses[j] > poses[i] && !uniquePos.count(poses[j])) {
                rank += 1;
                uniquePos.insert(poses[j]);
            }
        }

        cout << rank << "\n";
    }

    return 0;
}