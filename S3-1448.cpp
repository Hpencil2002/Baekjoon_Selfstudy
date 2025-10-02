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

    sort(vc.begin(), vc.end(), greater<int>());

    int index = 0;
    while (true) {
        if (vc[index] < vc[index + 1] + vc[index + 2]) {
            cout << vc[index] + vc[index + 1] + vc[index + 2];
            break;
        }

        index += 1;
        if (index + 2 >= N) {
            cout << -1;
            break;
        }
    }

    return 0;
}