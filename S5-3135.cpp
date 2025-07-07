#include <iostream>
#include <cmath>
using namespace std;

int A, B, N;
int favorite[5];

int main() {
    cin >> A >> B >> N;
    for (int i = 0; i < N; i++) {
        cin >> favorite[i];
    }

    int index = 0;
    int min_diff = 987654321;
    for (int i = 0; i < N; i++) {
        int diff = abs(B - favorite[i]);
        if (min_diff > diff) {
            min_diff = diff;
            index = i;
        }
    }

    cout << (abs(A - B) < 1 + abs(favorite[index] - B) ? abs(A - B) : 1 + abs(favorite[index] - B));

    return 0;
}