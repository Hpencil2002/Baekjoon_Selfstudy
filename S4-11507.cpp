#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    cin >> str;

    bool** cards = new bool*[4];
    bool isDuplicated = false;
    for (int i = 0; i < 4; i++) {
        cards[i] = new bool[13];

        for (int j = 0; j < 13; j++) {
            cards[i][j] = false;
        }
    }

    for (int i = 0; i < str.size(); i += 3) {
        int num = (str[i + 1] - '0') * 10 + (str[i + 2] - '0');
        int index = 0;

        if (str[i] == 'P') {
            index = 0;
        }
        else if (str[i] == 'K') {
            index = 1;
        }
        else if (str[i] == 'H') {
            index = 2;
        }
        else {
            index = 3;
        }

        if (cards[index][num - 1]) {
            cout << "GRESKA\n";
            isDuplicated = true;
            break;
        }
        else {
            cards[index][num - 1] = true;
        }
    }

    if (!isDuplicated) {
        for (int i = 0; i < 4; i++) {
            int cnt = 0;

            for (int j = 0; j < 13; j++) {
                if (!cards[i][j]) {
                    cnt += 1;
                }
            }

            cout << cnt << ' ';
        }
    }

    return 0;
}