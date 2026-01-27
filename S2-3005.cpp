#include <iostream>
#include <string>
using namespace std;

int R, C;
string board[21];
string ans = "zzzzzzzzzzzzzzzzzzzz";

int main() {
    cin >> R >> C;
    for (int i = 0; i < R; i++) {
        cin >> board[i];
    }

    for (int i = 0; i < R; i++) {
        string str = "";

        for (int j = 0; j < C; j++) {
            if (board[i][j] == '#') {
                if (str.length() >= 2 && ans > str) {
                    ans = str;
                }

                str = "";
            }
            else {
                str += board[i][j];
            }
        }
        if (str.length() >= 2 && ans > str) {
            ans = str;
        }
    }

    for (int j = 0; j < C; j++) {
        string str = "";

        for (int i = 0; i < R; i++) {
            if (board[i][j] == '#') {
                if (str.length() >= 2 && ans > str) {
                    ans = str;
                }

                str = "";
            }
            else {
                str += board[i][j];
            }
        }
        if (str.length() >= 2 && ans > str) {
            ans = str;
        }
    }

    cout << ans;

    return 0;
}