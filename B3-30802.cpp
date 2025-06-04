#include <iostream>
using namespace std;

int main() {
    int N, T, P;
    int size[6] = {0, };

    cin >> N;
    for (int i = 0; i < 6; i++) {
        cin >> size[i];
    }
    cin >> T >> P;

    int ans_T = 0;
    for (int i = 0; i < 6; i++) {
        ans_T += (size[i] + T - 1) / T;
    }

    cout << ans_T << "\n";
    cout << N / P << " " << N % P;

    return 0;
}