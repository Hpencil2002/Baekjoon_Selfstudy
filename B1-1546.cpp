#include <iostream>
using namespace std;

int main() {
    int n;
    int *score;
    double *change;
    cin >> n;

    score = new int[n];
    change = new double[n];
    for (int i = 0; i < n; i++) {
        cin >> score[i];
        change[i] = score[i];
    }

    int m = 0;
    for (int i = 0; i < n; i++) {
        if (score[i] > m) {
            m = score[i];
        }
    }
    for (int i = 0; i < n; i++) {
        change[i] = change[i] / m * 100;
    }

    double hap = 0;
    for (int i = 0; i < n; i++) {
        hap += change[i];
    }
    double avg = hap / n;

    cout << avg;

    return 0;
}