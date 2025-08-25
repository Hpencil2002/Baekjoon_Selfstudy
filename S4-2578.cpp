#include <iostream>
using namespace std;

int board[5][5];
bool visit[5][5];

int check1() {
    int cnt = 0;

    for (int i = 0; i < 5; i++) {
        if (visit[i][0] && visit[i][1] && visit[i][2] && visit[i][3] && visit[i][4]) {
            cnt += 1;
        }
    }

    return cnt;
}

int check2() {
    int cnt = 0;

    for (int i = 0; i < 5; i++) {
        if (visit[0][i] && visit[1][i] && visit[2][i] && visit[3][i] && visit[4][i]) {
            cnt += 1;
        }
    }

    return cnt;
}

int check3() {
    int cnt = 0;

    if (visit[0][0] && visit[1][1] && visit[2][2] && visit[3][3] && visit[4][4]) {
        cnt += 1;
    }

    return cnt;
}

int check4() {
    int cnt = 0;

    if (visit[0][4] && visit[1][3] && visit[2][2] && visit[3][1] && visit[4][0]) {
        cnt += 1;
    }

    return cnt;
}

int main() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> board[i][j];
        }
    }

    for (int k = 0; k < 25; k++) {
        int num;
        cin >> num;

        int cnt = 0;
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (board[i][j] == num) {
                    visit[i][j] = true;
                }
            }
        }

        cnt += check1();
        cnt += check2();
        cnt += check3();
        cnt += check4();

        if (cnt >= 3) {
            cout << k + 1;
            return 0;
        }
    }
}