#include <iostream>
using namespace std;

int main() {
    int C;
    cin >> C;

    for (int i = 0; i < C; i++) {
        int N, avg = 0;
        int *score;

        cin >> N;

        score = new int[N];
        for (int j = 0; j < N; j++) {
            cin >> score[j];
            avg += score[j];
        }
        avg /= N;

        int cnt = 0;
        for (int k = 0; k < N; k++) {
            if (score[k] > avg) {
                cnt++;
            }
        }

        double rate = (double)cnt / N * 100;

        cout << fixed;
        cout.precision(3);
        cout << rate << "%\n";

        delete[] score;
    }

    return 0;
}