#include <iostream>
#include <cmath>
using namespace std;

int N, K;
int arr[501];

double calcSD(int head, int tail) {
    double mean = 0;
    double sd = 0;
    int num = tail - head + 1;

    for (int i = head; i <= tail; i++) {
        mean += arr[i];
    }
    mean /= num;

    for (int i = head; i <= tail; i++) {
        double tmp = arr[i] - mean;
        tmp *= tmp;
        sd += tmp;
    }
    sd /= num;
    sd = sqrt(sd);

    return sd;
}

double solve() {
    int head = 0;
    int tail = 0;
    double res = 987654321;

    for (int i = K - 1; i < N; i++) {
        head = 0;
        tail = i;

        while (tail < N) {
            double tmp = calcSD(head, tail);

            if (res >= tmp) {
                res = tmp;
            }

            head += 1;
            tail += 1;
        }
    }

    return res;
}

int main() {
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    cout.precision(10);
    cout << solve();

    return 0;
}