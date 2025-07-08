#include <iostream>
using namespace std;

int main() {
    int N, score, P;
    cin >> N >> score >> P;

    int board[100];
    for (int i = 0; i < N; i++) {
        cin >> board[i];
    }

    int cnt = 0;
    int rank = 1;
    for (int i = 0; i < N; i++) {
        if (board[i] > score) {
            rank += 1;
        }
        else if (board[i] == score) {
            rank = rank;
        }
        else {
            break;
        }

        cnt += 1;
    }

    if (cnt == P) {
        rank = -1;
    }
    if (N == 0) {
        rank = 1;
    }

    cout << rank;

    return 0;
}