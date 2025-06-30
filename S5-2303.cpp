#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    int card[1001][5];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> card[i][j];
        }
    }

    int max = 0;
    int index = 0;
    int score[1001] = { 0, };

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 5; j++) {
            for (int k = j + 1; k < 5; k++) {
                for (int l = k + 1; l < 5; l++) {
                    if (score[i] < (card[i][j] + card[i][k] + card[i][l]) % 10) {
                        score[i] = (card[i][j] + card[i][k] + card[i][l]) % 10;
                    }
                }
            }
        }
    }

    for (int i = 0; i < N; i++) {
        if (max < score[i]) {
            max = score[i];
            index = i;
        }

        if (max == score[i]) {
            if (i > index) {
                index = i;
            }
        }
    }

    cout << index + 1;

    return 0;
}