#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

char card[102][102];
int R, C;
int A, B;

void MakeCard() {
    for (int i = 0; i < R; i++) {
        for (int j = C; j < 2 * C; j++) {
            card[i][j] = card[i][(C - 1) - (j - C)];
        }
    }

    for (int i = R; i < 2 * R; i++) {
        for (int j = 0; j < 2 * C; j++) {
            card[i][j] = card[(R - 1) - (i - R)][j];
        }
    }
}

void ChangeCard() {
    if (card[A][B] == '.') {
        card[A][B] = '#';
    }
    else {
        card[A][B] = '.';
    }
}

void PrintCard() {
    for (int i = 0; i < 2 * R; i++) {
        for (int j = 0; j < 2 * C; j++) {
            cout << card[i][j];
        }

        cout << "\n";
    }
}

int main() {
    cin >> R >> C;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> card[i][j];
        }
    }

    cin >> A >> B;
    A -= 1;
    B -= 1;

    MakeCard();
    ChangeCard();
    PrintCard();

    return 0;
}