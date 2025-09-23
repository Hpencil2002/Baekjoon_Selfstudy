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

    if (prev_permutation(vc.begin(), vc.end())) {
        for (int i = 0; i < vc.size(); i++) {
            cout << vc[i] << ' ';
        }
    }
    else {
        cout << -1;
    }

    return 0;
}