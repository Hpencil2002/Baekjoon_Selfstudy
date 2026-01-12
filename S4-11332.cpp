#include <iostream>
#include <string>
#include <cmath>
using namespace std;

#define MAX 100000000

int C;
string S;
long long N, T, L;

int main() {
    cin >> C;

    while (C--) {
        cin >> S >> N >> T >> L;

        if (S == "O(N)") {
            long long sum = N * T;

            if (sum <= L * MAX) {
                cout << "May Pass.\n";
            }
            else {
                cout << "TLE!\n";
            }
        }
        else if (S == "O(N^2)") {
            if (N >= 31623) {
                cout << "TLE!\n";
            }
            else {
                long long sum = N * N * T;

                if (sum <= L * MAX) {
                    cout << "May Pass.\n";
                }
                else {
                    cout << "TLE!\n";
                }
            }
        }
        else if (S == "O(N^3)") {
            if (N >= 1001) {
                cout << "TLE!\n";
            }
            else {
                long long sum = N * N * N * T;

                if (sum <= L * MAX) {
                    cout << "May Pass.\n";
                }
                else {
                    cout << "TLE!\n";
                }
            }
        }
        else if (S == "O(2^N)") {
            if (N >= 30) {
                cout << "TLE!\n";
            }
            else {
                long long sum = (long long)pow(2, N) * T;

                if (sum <= L * MAX) {
                    cout << "May Pass.\n";
                }
                else {
                    cout << "TLE!\n";
                }
            }
        }
        else if (S == "O(N!)") {
            if (N >= 13) {
                cout << "TLE!\n";
            }
            else {
                long long sum = T;
                for (long long i = 1; i <= N; i++) {
                    sum *= i;
                }

                if (sum <= L * MAX) {
                    cout << "May Pass.\n";
                }
                else {
                    cout << "TLE!\n";
                }
            }
        }
    }

    return 0;
}