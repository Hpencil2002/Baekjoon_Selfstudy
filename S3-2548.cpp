#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> vc = vector<int>(N);
    for (int i = 0; i < N; i++) {
        cin >> vc[i];
    }

    sort(vc.begin(), vc.end());

    if (N % 2 == 0) {
        cout << vc[N / 2 - 1];
    }
    else {
        cout << vc[N / 2];
    }

    return 0;
}