#include <iostream>
#include <string>
using namespace std;

int s, n;

void PrintSpace(int s) {
    for (int i = 0; i < s + 2; i++) {
        cout << ' ';
    }
}

void PrintHorizon(int s) {
    cout << ' ';

    for (int i = 0; i < s; i++) {
        cout << '-';
    }

    cout << ' ';
}

void PrintVerRight(int s) {
    for (int i = 0; i < s + 1; i++) {
        cout << ' ';
    }

    cout << '|';
}

void PrintVerLeft(int s) {
    cout << '|';

    for (int i = 0; i < s + 1; i++) {
        cout << ' ';
    }
}

void PrintVerBoth(int s) {
    cout << '|';

    for (int i = 0; i < s; i++) {
        cout << ' ';
    }

    cout << '|';
}

void PrintOne(int s, int row) {
    if (row == 1 || row == s + 2 || row == 2 * s + 3) {
        PrintSpace(s);
    }
    else {
        PrintVerRight(s);
    }
}

void PrintTwo(int s, int row) {
    if (row == 1 || row == s + 2 || row == 2 * s + 3) {
        PrintHorizon(s);
    }
    else if (2 <= row && row <= s + 1) {
        PrintVerRight(s);
    }
    else {
        PrintVerLeft(s);
    }
}

void PrintThree(int s, int row) {
    if (row == 1 || row == s + 2 || row == 2 * s + 3) {
        PrintHorizon(s);
    }
    else {
        PrintVerRight(s);
    }
}

void PrintFour(int s, int row) {
    if (row == 1 || row == 2 * s + 3) {
        PrintSpace(s);
    }
    else if (row == s + 2) {
        PrintHorizon(s);
    }
    else if (2 <= row && row <= s + 1) {
        PrintVerBoth(s);
    }
    else {
        PrintVerRight(s);
    }
}

void PrintFive(int s, int row) {
    if (row == 1 || row == s + 2 || row == 2 * s + 3) {
        PrintHorizon(s);
    }
    else if (2 <= row && row <= s + 1) {
        PrintVerLeft(s);
    }
    else {
        PrintVerRight(s);
    }
}

void PrintSix(int s, int row) {
    if (row == 1 || row == s + 2 || row == 2 * s + 3) {
        PrintHorizon(s);
    }
    else if (2 <= row && row <= s + 1) {
        PrintVerLeft(s);
    }
    else {
        PrintVerBoth(s);
    }
}

void PrintSeven(int s, int row) {
    if (row == 1) {
        PrintHorizon(s);
    }
    else if (row == s + 2 || row == 2 * s + 3) {
        PrintSpace(s);
    }
    else {
        PrintVerRight(s);
    }
}

void PrintEight(int s, int row) {
    if (row == 1 || row == s + 2 || row == 2 * s + 3) {
        PrintHorizon(s);
    }
    else {
        PrintVerBoth(s);
    }
}

void PrintNine(int s, int row) {
    if (row == 1 || row == s + 2 || row == 2 * s + 3) {
        PrintHorizon(s);
    }
    else if (2 <= row && row <= s + 1) {
        PrintVerBoth(s);
    }
    else {
        PrintVerRight(s);
    }
}

void PrintZero(int s, int row) {
    if (row == 1 || row == 2 * s + 3) {
        PrintHorizon(s);
    }
    else if (row == s + 2) {
        PrintSpace(s);
    }
    else {
        PrintVerBoth(s);
    }
}

int main() {
    cin >> s >> n;

    int height = 2 * s + 3;
    string N = to_string(n);

    for (int row = 1; row <= height; row++) {
        for (int i = 0; i < N.size(); i++) {
            if (N[i] == '1') {
                PrintOne(s, row);
            }
            else if (N[i] == '2') {
                PrintTwo(s, row);
            }
            else if (N[i] == '3') {
                PrintThree(s, row);
            }
            else if (N[i] == '4') {
                PrintFour(s, row);
            }
            else if (N[i] == '5') {
                PrintFive(s, row);
            }
            else if (N[i] == '6') {
                PrintSix(s, row);
            }
            else if (N[i] == '7') {
                PrintSeven(s, row);
            }
            else if (N[i] == '8') {
                PrintEight(s, row);
            }
            else if (N[i] == '9') {
                PrintNine(s, row);
            }
            else if (N[i] == '0') {
                PrintZero(s, row);
            }

            cout << ' ';
        }

        cout << "\n";
    }

    return 0;
}