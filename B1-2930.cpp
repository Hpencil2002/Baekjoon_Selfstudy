#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int check(char base, char fr) {
    if (base == 'S') {
        if (fr == 'S') {
            return 1;
        }
        if (fr == 'P') {
            return 2;
        }
        if (fr == 'R') {
            return 0;
        }
    }

    if (base == 'P') {
        if (fr == 'S') {
            return 0;
        }
        if (fr == 'P') {
            return 1;
        }
        if (fr == 'R') {
            return 2;
        }
    }

    if (base == 'R') {
        if (fr == 'S') {
            return 2;
        }
        if (fr == 'P') {
            return 0;
        }
        if (fr == 'R') {
            return 1;
        }
    }
}

int main() {
    int R;
    cin >> R;

    vector<char> round(R);
    for (int i = 0; i < R; i++) {
        cin >> round[i];
    }

    int N;
    cin >> N;

    vector<vector<char>> friends(N, vector<char>(R));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < R; j++) {
            cin >> friends[i][j];
        }
    }

    int score = 0, maxScore = 0;
    for (int j = 0; j < R; j++) {
        int arr[3] = { 0, };

        for (int i = 0; i < N; i++) {
            arr[0] += check('S', friends[i][j]);
            arr[1] += check('P', friends[i][j]);
            arr[2] += check('R', friends[i][j]);

            score += check(round[j], friends[i][j]);
        }

        maxScore += max(arr[0], max(arr[1], arr[2]));
    }

    cout << score << "\n" << maxScore;

    return 0;
}