#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    string frame[5];

    cin >> str;

    frame[0] = "..#..";
    for (int i = 1; i < str.size(); i++) {
        if (i % 3 != 2) {
            frame[0] += ".#..";
        }
        else {
            frame[0] += ".*..";
        }
    }
    frame[4] = frame[0];

    frame[1] = ".#.#.";
    for (int i = 1; i < str.size(); i++) {
        if (i % 3 != 2) {
            frame[1] += "#.#.";
        }
        else {
            frame[1] += "*.*.";
        }
    }
    frame[3] = frame[1];

    frame[2] = "#.";
    frame[2] += str[0];
    frame[2] += ".#";
    for (int i = 1; i < str.size(); i++) {
        if (i % 3 == 1) {
            frame[2] += ".";
            frame[2] += str[i];
            if (i == str.size() - 1) {
                frame[2] += ".#";
            }
            else {
                frame[2] += ".*";
            }
        }
        else if (i % 3 == 2) {
            frame[2] += ".";
            frame[2] += str[i];
            frame[2] += ".*";
        }
        else {
            frame[2] += ".";
            frame[2] += str[i];
            frame[2] += ".#";
        }
    }

    for (int i = 0; i < 5; i++) {
        cout << frame[i] << "\n";
    }

    return 0;
}