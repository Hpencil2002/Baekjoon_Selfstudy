#include <iostream>
#include <string>
using namespace std;

string str;

bool checkX(char arr[3][3]) {
    for (int i = 0; i < 3; i++) {
        if (arr[i][0] == 'X' && arr[i][0] == arr[i][1] && arr[i][1] == arr[i][2]) {
            return true;
        }
        if (arr[0][i] == 'X' && arr[0][i] == arr[1][i] && arr[1][i] == arr[2][i]) {
            return true;
        }
    }

    if (arr[0][0] == 'X' && arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2]) {
        return true;
    }
    if (arr[0][2] == 'X' && arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0]) {
        return true;
    }

    return false;
}

bool checkO(char arr[3][3]) {
    for (int i = 0; i < 3; i++) {
        if (arr[i][0] == 'O' && arr[i][0] == arr[i][1] && arr[i][1] == arr[i][2]) {
            return true;
        }
        if (arr[0][i] == 'O' && arr[0][i] == arr[1][i] && arr[1][i] == arr[2][i]) {
            return true;
        }
    }

    if (arr[0][0] == 'O' && arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2]) {
        return true;
    }
    if (arr[0][2] == 'O' && arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0]) {
        return true;
    }

    return false;
}

int main() {
    while (true) {
        char arr[3][3];
        cin >> str;
        if (str == "end") {
            return 0;
        }

        int x = 0;
        int o = 0;
        for (int i = 0; i < 9; i++) {
            arr[i / 3][i % 3] = str[i];

            if (str[i] == 'X') {
                x += 1;
            }
            else if (str[i] == 'O') {
                o += 1;
            }
        }

        bool isX = checkX(arr);
        bool isO = checkO(arr);
        if (isX && !isO && x == o + 1) {
            cout << "valid\n";
        }
        else if (!isX && isO && x == o) {
            cout << "valid\n";
        }
        else if (!isX && !isO && x == 5 && o == 4) {
            cout << "valid\n";
        }
        else {
            cout << "invalid\n";
        }
    }
}