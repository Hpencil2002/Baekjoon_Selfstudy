#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, X;
    cin >> N >> X;

    vector<int> vc = vector<int>(N);
    for (int i = 0; i < N; i++) {
        cin >> vc[i];
    }

    vector<int> ssum = vector<int>(N - X + 1, 0);
    for (int i = 0; i < X; i++) {
        ssum[0] += vc[i];
    }
    for (int i = 1; i < N - X + 1; i++) {
        ssum[i] = ssum[i - 1] + vc[i + X - 1] - vc[i - 1];
    }

    int num = *max_element(ssum.begin(), ssum.end());
    if (num == 0) {
        cout << "SAD";
    }
    else {
        cout << num << "\n";
        cout << count(ssum.begin(), ssum.end(), num);
    }

    return 0;
}